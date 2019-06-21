--- Common/city.cc.orig	2018-09-21 23:44:14 UTC
+++ Common/city.cc
@@ -65,6 +65,10 @@ static uint32 UNALIGNED_LOAD32(const char *p) {
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 #include <byteswap.h>
 #endif
