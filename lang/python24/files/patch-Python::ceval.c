--- Python/ceval.c.orig	Wed Nov 24 03:06:08 2004
+++ Python/ceval.c	Wed Dec  1 22:29:37 2004
@@ -414,8 +414,11 @@
 
 /* The interpreter's recursion limit */
 
-static int recursion_limit = 1000;
-int _Py_CheckRecursionLimit = 1000;
+#ifndef PYTHON_DEFAULT_RECURSION_LIMIT
+#define PYTHON_DEFAULT_RECURSION_LIMIT 1000
+#endif
+static int recursion_limit = PYTHON_DEFAULT_RECURSION_LIMIT;
+int _Py_CheckRecursionLimit = PYTHON_DEFAULT_RECURSION_LIMIT;
 
 int
 Py_GetRecursionLimit(void)
