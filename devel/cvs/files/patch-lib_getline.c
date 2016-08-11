--- lib/getline.c.orig	2012-01-21 05:30:24 UTC
+++ lib/getline.c
@@ -155,7 +155,7 @@ getstr (lineptr, n, stream, terminator, 
 }
 
 int
-getline (lineptr, n, stream)
+get_line (lineptr, n, stream)
      char **lineptr;
      size_t *n;
      FILE *stream;
