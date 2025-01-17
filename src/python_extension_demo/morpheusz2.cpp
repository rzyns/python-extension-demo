#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
// c++ -O3 -Wall -shared -std=c++11 -fPIC \
    "$(pybind11-config --includes)" \
    ./src/python_extension_demo/morpheusz2.cpp \
    -o "morpheusz2$(python3-config --extension-suffix)"
