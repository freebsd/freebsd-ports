--- /src/myndbm.c.orig        2011-01-10 23:53:25.000000000 +0000
+++ src/myndbm.c     2011-01-10 23:53:33.000000000 +0000
@@ -213,7 +213,7 @@
 mydbm_load_file (FILE *fp, List *list, char *filename)
 {
     char *line = NULL;
-    size_t line_size;
+    size_t line_size = 0;
     char *value;
     size_t value_allocated;
     char *cp, *vp;



