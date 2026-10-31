--- src/liboslquery/py_osl.h.orig	2025-12-01 12:53:35 UTC
+++ src/liboslquery/py_osl.h
@@ -29,6 +29,13 @@
 
 #include <Imath/half.h>
 
+#if PY_VERSION_HEX >= 0x030b00a6 && PY_VERSION_HEX < 0x030d0000
+#  ifndef Py_BUILD_CORE
+#    define Py_BUILD_CORE 1
+#  endif
+#  include "internal/pycore_frame.h"
+#endif
+
 #include <pybind11/numpy.h>
 #include <pybind11/operators.h>
 #include <pybind11/pybind11.h>
