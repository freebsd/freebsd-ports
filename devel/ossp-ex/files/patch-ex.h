--- ex.h.orig	Wed Mar 24 18:13:57 2004
+++ ex.h	Wed Mar 24 18:14:09 2004
@@ -86,9 +86,9 @@
     void *ex_object;
     void *ex_value;
     /* throw point */
-    char *ex_file;
+    const char *ex_file;
     int   ex_line;
-    char *ex_func;
+    const char *ex_func;
 } ex_t;
 
 /* declare the context type (private) */
