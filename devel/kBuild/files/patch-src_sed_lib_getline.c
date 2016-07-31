--- src/sed/lib/getline.c.orig	2012-07-17 22:30:18 UTC
+++ src/sed/lib/getline.c
@@ -31,7 +31,7 @@
    null terminator), or -1 on error or EOF.  */
 
 size_t
-getline (lineptr, n, stream)
+get_line (lineptr, n, stream)
      char **lineptr;
      size_t *n;
      FILE *stream;
