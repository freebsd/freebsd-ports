--- src/python/py_oiio.h.orig	2022-02-27 08:12:20 UTC
+++ src/python/py_oiio.h
@@ -41,6 +41,13 @@ OIIO_CLANG_PRAGMA(GCC diagnostic ignored "-Wunused-val
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
