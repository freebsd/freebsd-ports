--- lib/getline.c.orig	Fri Feb 14 20:42:13 2003
+++ lib/getline.c	Fri Feb 14 20:44:09 2003
@@ -43,6 +43,9 @@
 
 # include "getstr.h"
 
+int getline (char **, size_t *, FILE *);
+int getdelim (char **, size_t *, int, FILE *);
+
 int
 getline (char **lineptr, size_t *n, FILE *stream)
 {
