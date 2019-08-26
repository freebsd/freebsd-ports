--- md5/md5.c.orig	2019-08-25 00:26:22 UTC
+++ md5/md5.c
@@ -31,6 +31,8 @@
 
 #include "./md5.h"
 
+#include <sys/endian.h>
+
 #ifdef __amigaos4__
 #include <machine/endian.h>
 #define le32toh(x) (((x & 0xff) << 24) | \
