--- Python/ceval.c.orig	Sat Dec 20 15:13:53 2003
+++ Python/ceval.c	Sat Dec 20 15:15:46 2003
@@ -496,7 +496,10 @@
 
 /* The interpreter's recursion limit */
 
-static int recursion_limit = 1000;
+#ifndef PYTHON_DEFAULT_RECURSION_LIMIT
+#define PYTHON_DEFAULT_RECURSION_LIMIT 1000
+#endif
+static int recursion_limit = PYTHON_DEFAULT_RECURSION_LIMIT;
 
 int
 Py_GetRecursionLimit(void)
