from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension(
    "line_profiler._line_profiler",
    sources=[
        "line_profiler/_line_profiler.pyx",
        "line_profiler/timers.c",
        "line_profiler/c_trace_callbacks.c",
    ],
    language="c++",
    depends=["line_profiler/_map_helpers.pxd"],
)

setup(ext_modules=cythonize([ext]))
