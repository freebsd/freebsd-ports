--- siplib.c.orig	2022-02-01 13:29:23 UTC
+++ siplib.c
@@ -20,6 +20,12 @@
 #include <Python.h>
 #include <datetime.h>
 #include <frameobject.h>
+#if PY_VERSION_HEX >= 0x030b00a6
+   #ifndef Py_BUILD_CORE
+     #define Py_BUILD_CORE 1
+   #endif
+   #include "internal/pycore_frame.h"
+#endif
 
 #include <assert.h>
 #include <stdio.h>
