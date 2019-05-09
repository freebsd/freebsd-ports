$NetBSD$

# Portability

--- src/city.cc.orig	2019-04-30 11:57:32 UTC
+++ src/city.cc
@@ -60,6 +60,13 @@ static uint32 UNALIGNED_LOAD32(const char *p) {
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined(__FreeBSD__)
+
+#include <sys/endian.h>
+
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
 #elif defined(__NetBSD__)
 
 #include <sys/types.h>
