--- sip_core.c.orig	2022-06-17 14:27:21 UTC
+++ sip_core.c
@@ -20,6 +20,12 @@
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
