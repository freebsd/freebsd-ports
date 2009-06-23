--- lib/md5/getline.h.orig	2009-06-18 13:54:02.000000000 +0200
+++ lib/md5/getline.h	2009-06-18 13:56:18.000000000 +0200
@@ -34,8 +34,13 @@
 int
 getline PARAMS ((char **_lineptr, size_t *_n, FILE *_stream));
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 800067 
 int
 getdelim PARAMS ((char **_lineptr, size_t *_n, int _delimiter, FILE *_stream));
+#endif
+#endif
 
 /*
  * # endif
