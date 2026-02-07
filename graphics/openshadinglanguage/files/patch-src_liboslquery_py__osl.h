--- src/liboslquery/py_osl.h.orig	2022-01-08 02:36:45 UTC
+++ src/liboslquery/py_osl.h
@@ -31,6 +31,13 @@
 #    include <OpenEXR/half.h>
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
