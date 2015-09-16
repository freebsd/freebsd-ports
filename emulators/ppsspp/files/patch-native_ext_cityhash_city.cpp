--- native/ext/cityhash/city.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/ext/cityhash/city.cpp
@@ -68,12 +68,12 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_32(x) BSWAP_32(x)
 #define bswap_64(x) BSWAP_64(x)
 
-#elif defined(__FreeBSD__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #define bswap_32(x) bswap32(x)
 #define bswap_64(x) bswap64(x)
 
-#elif defined(__OpenBSD__)
+#elif defined(__Bitrig__) || defined(__OpenBSD__)
 #include <sys/types.h>
 #define bswap_32(x) swap32(x)
 #define bswap_64(x) swap64(x)
