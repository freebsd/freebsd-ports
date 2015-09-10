--- source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2015-06-12 20:48:15.000000000 -0500
+++ source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2015-06-12 20:48:41.000000000 -0500
@@ -94,6 +94,7 @@
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
 #else
+#if !defined __FreeBSD__
 static inline uint32_t bswap32(uint32_t val)
 {
 	return (((val & 0xff000000) >> 24) |
@@ -102,6 +103,7 @@
 		((val & 0x000000ff) << 24));
 }
 #endif
+#endif
 
 #define ALOWORD(x)   (*((uint16_t*)&(x)))   // low word
 
