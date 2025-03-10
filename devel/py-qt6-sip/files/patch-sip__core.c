--- sip_core.c.orig	2024-12-12 10:04:05 UTC
+++ sip_core.c
@@ -11,6 +11,12 @@
 #define PY_SSIZE_T_CLEAN
 #include <Python.h>
 #include <datetime.h>
+#if PY_VERSION_HEX >= 0x030b00a6
+   #ifndef Py_BUILD_CORE
+     #define Py_BUILD_CORE 1
+   #endif
+   #include "internal/pycore_frame.h"
+#endif
 
 #include <assert.h>
 #include <stdio.h>
