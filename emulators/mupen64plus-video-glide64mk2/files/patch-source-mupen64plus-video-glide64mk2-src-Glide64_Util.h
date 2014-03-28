--- source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2013-07-03 19:28:17.000000000 -0500
+++ source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2014-03-23 16:59:30.000000000 -0500
@@ -90,12 +90,11 @@
 			lx = lc; \
 		}
 
-#if defined(__GNUC__)
-  #define bswap32(x) __builtin_bswap32(x)
-#elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
+#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
 #else
+#if !defined __FreeBSD__
 static inline uint32_t bswap32(uint32_t val)
 {
 	return (((val & 0xff000000) >> 24) |
@@ -104,6 +103,7 @@
 		((val & 0x000000ff) << 24));
 }
 #endif
+#endif
 
 #define ALOWORD(x)   (*((uint16_t*)&(x)))   // low word
 
