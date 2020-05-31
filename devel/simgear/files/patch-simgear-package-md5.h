--- simgear/package/md5.h.orig	2020-05-22 20:11:33 UTC
+++ simgear/package/md5.h
@@ -23,6 +23,8 @@
 typedef unsigned char    u_int8_t;
 typedef unsigned int     u_int32_t;
 typedef unsigned __int64 u_int64_t;
+#else
+#include <sys/types.h>
 #endif
      
 #define	MD5_BLOCK_LENGTH		64
