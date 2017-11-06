--- src/sed/lib/getline.c.orig	2017-07-18 19:08:55 UTC
+++ src/sed/lib/getline.c
@@ -33,7 +33,7 @@
    null terminator), or -1 on error or EOF.  */
 
 size_t
-getline (lineptr, n, stream)
+get_line (lineptr, n, stream)
      char **lineptr;
      size_t *n;
      FILE *stream;
