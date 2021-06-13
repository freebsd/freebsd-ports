--- extensions/_libastro.c.orig	2021-06-12 19:13:26 UTC
+++ extensions/_libastro.c
@@ -1,5 +1,6 @@
 /* Python header files. */
 
+#define PY_SSIZE_T_CLEAN
 #include "Python.h"
 
 #if PY_MAJOR_VERSION == 2
