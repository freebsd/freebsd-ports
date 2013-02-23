--- src/city.cc.orig	2012-12-24 12:40:59.863562632 +0400
+++ src/city.cc	2012-12-24 12:48:07.077276386 +0400
@@ -60,6 +60,12 @@
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined __FreeBSD__
+
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
 #else
 
 #include <byteswap.h>
