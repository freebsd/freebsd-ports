--- ts.c.orig	Wed Mar 24 17:36:35 2004
+++ ts.c	Wed Mar 24 17:36:49 2004
@@ -202,7 +202,7 @@
 
     if (format == NULL || ap == NULL)
         return NULL;
-    ap2 = ap;
+    va_copy(ap2, ap);
     if ((n = ts_suite_mvxprintf(NULL, 0, format, ap)) == -1)
         return NULL;
     if ((buffer = (char *)malloc(n+1)) == NULL)
