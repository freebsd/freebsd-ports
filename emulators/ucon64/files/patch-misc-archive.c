--- misc/archive.c.orig	2013-02-24 18:51:23.157943222 -0800
+++ misc/archive.c	2013-02-24 18:55:00.666943043 -0800
@@ -27,6 +27,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/stat.h>
+#define Z_SOLO
 #include <zlib.h>
 #ifdef  HAVE_BYTESWAP_H
 #include <byteswap.h>
