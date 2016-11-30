--- simgear/package/md5.h.orig	2016-11-22 11:03:23.506026000 +0000
+++ simgear/package/md5.h	2016-11-22 11:08:06.727103000 +0000
@@ -23,6 +23,8 @@
 typedef unsigned char    u_int8_t;
 typedef unsigned int     u_int32_t;
 typedef unsigned __int64 u_int64_t;
+#else
+#include <sys/types.h>
 #endif
      
 #define	MD5_BLOCK_LENGTH		64
@@ -49,4 +51,4 @@
 
      
 
- 
\ No newline at end of file
+ 
