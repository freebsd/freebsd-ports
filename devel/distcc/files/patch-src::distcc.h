--- src/distcc.h.orig	Sun Sep 15 18:20:01 2002
+++ src/distcc.h	Sun Sep 15 18:18:53 2002
@@ -102,6 +102,7 @@
 
 
 /* bulk.c */
+#include <sys/stat.h>
 int dcc_open_read(const char *fname, int *ifd, off_t *fsize);
 
 
