--- Common/city.cc.orig	2022-05-11 22:23:32 UTC
+++ Common/city.cc
@@ -70,6 +70,10 @@ static uint32 UNALIGNED_LOAD32(const char *p) {
 #define bswap_32(x) bswap32(x)
 #define bswap_64(x) bswap64(x)
 
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 #include <byteswap.h>
 #endif
