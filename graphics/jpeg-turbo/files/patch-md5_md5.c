--- md5/md5.c.orig	2017-07-07 20:31:10 UTC
+++ md5/md5.c
@@ -54,6 +54,8 @@ static void MD5Transform(unsigned int [4
 #include <libkern/OSByteOrder.h>
 #define le32toh(x) OSSwapLittleToHostInt32(x)
 #define htole32(x) OSSwapHostToLittleInt32(x)
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #endif
 
 /*
