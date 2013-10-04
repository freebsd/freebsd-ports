--- source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2013-10-04 04:04:30.000000000 -0500
+++ source/mupen64plus-video-glide64mk2/src/Glide64/Util.h	2013-10-04 04:04:41.000000000 -0500
@@ -90,9 +90,7 @@
 			lx = lc; \
 		}
 
-#if defined(__GNUC__)
-  #define bswap32(x) __builtin_bswap32(x)
-#elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
+#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
 #else
