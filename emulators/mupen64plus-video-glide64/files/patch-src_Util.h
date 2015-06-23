--- mupen64plus-video-glide64/src/Util.h.orig	2015-06-19 14:41:15 UTC
+++ mupen64plus-video-glide64/src/Util.h
@@ -93,7 +93,9 @@ void fix_tex_coord (VERTEX **v);
             lx = lc; \
         }
 
-#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
+#if defined(__FreeBSD__)
+  #include <sys/endian.h>
+#elif defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
   #include <stdlib.h>
   #define bswap32(x) _byteswap_ulong(x)
 #else
