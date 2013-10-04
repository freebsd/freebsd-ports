--- mupen64plus-video-glide64/src/rdp.cpp	2013-10-04 03:41:54.000000000 -0500
+++ mupen64plus-video-glide64/src/rdp.cpp	2013-10-04 03:43:26.000000000 -0500
@@ -67,21 +67,6 @@
 
 int drawFlag = 1;	// draw flag for rendering callback
 
-#if defined(__GNUC__)
-  #define bswap32(x) __builtin_bswap32(x)
-#elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
-  #include <stdlib.h>
-  #define bswap32(x) _byteswap_ulong(x)
-#else
-static inline uint32_t bswap32(uint32_t val)
-{
-        return (((val & 0xff000000) >> 24) |
-                ((val & 0x00ff0000) >>  8) |
-                ((val & 0x0000ff00) <<  8) |
-                ((val & 0x000000ff) << 24));
-}
-#endif
-
 // global strings
 const char *ACmp[4] = { "NONE", "THRESHOLD", "UNKNOWN", "DITHER" };
 
