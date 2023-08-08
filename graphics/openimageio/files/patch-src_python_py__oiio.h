--- src/python/py_oiio.h.orig	2023-01-30 22:36:11 UTC
+++ src/python/py_oiio.h
@@ -42,6 +42,13 @@ OIIO_CLANG_PRAGMA(GCC diagnostic ignored "-Wunused-val
 OIIO_CLANG_PRAGMA(GCC diagnostic ignored "-Wunused-value")
 #endif
 
+#if PY_VERSION_HEX >= 0x030b00a6
+   #ifndef Py_BUILD_CORE
+     #define Py_BUILD_CORE 1
+   #endif
+   #include "internal/pycore_frame.h"
+#endif
+
 #include <pybind11/numpy.h>
 #include <pybind11/operators.h>
 #include <pybind11/pybind11.h>
