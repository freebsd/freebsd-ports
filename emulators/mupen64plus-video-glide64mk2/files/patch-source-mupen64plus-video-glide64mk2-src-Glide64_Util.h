--- source/mupen64plus-video-glide64mk2/src/Glide64/Util.h.orig	2013-07-03 20:28:17.000000000 -0400
+++ source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2014-09-01 12:32:50.282026994 -0400
@@ -40,6 +40,8 @@
 #ifndef Util_H
 #define Util_H
 
+#include <sys/endian.h>
+
 #define NOT_TMU0	0x00
 #define NOT_TMU1	0x01
 #define NOT_TMU2	0x02
@@ -90,12 +92,11 @@
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
@@ -104,6 +105,7 @@
 		((val & 0x000000ff) << 24));
 }
 #endif
+#endif
 
 #define ALOWORD(x)   (*((uint16_t*)&(x)))   // low word
 
