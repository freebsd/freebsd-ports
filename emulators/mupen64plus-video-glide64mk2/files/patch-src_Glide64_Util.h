--- src/Glide64/Util.h.orig	2024-01-06 03:12:23 UTC
+++ src/Glide64/Util.h
@@ -94,6 +94,7 @@ float ScaleZ(float z);
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
 #else
+#if !defined __FreeBSD__
 static inline uint32_t bswap32(uint32_t val)
 {
 	return (((val & 0xff000000) >> 24) |
@@ -101,6 +102,7 @@ static inline uint32_t bswap32(uint32_t val)
 		((val & 0x0000ff00) <<  8) |
 		((val & 0x000000ff) << 24));
 }
+#endif
 #endif
 
 #define ALOWORD(x)   (*((uint16_t*)&(x)))   // low word
