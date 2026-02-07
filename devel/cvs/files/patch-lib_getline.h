--- lib/getline.h.orig	2012-01-21 05:30:24 UTC
+++ lib/getline.h
@@ -12,7 +12,7 @@
 #define GETLINE_NO_LIMIT -1
 
 int
-  getline __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
+  get_line __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
 int
   getline_safe __PROTO ((char **_lineptr, size_t *_n, FILE *_stream,
                          int limit));
