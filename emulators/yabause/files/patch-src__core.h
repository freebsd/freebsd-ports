--- src/core.h.orig
+++ src/core.h
@@ -252,8 +252,10 @@
 # define BSWAP16(x)  ((__builtin_bswap16((x) >> 16) << 16) | __builtin_bswap16((x)))
 # define BSWAP16L(x) (__builtin_bswap16((x)))
 #endif
+#ifdef HAVE_BUILTIN_BSWAP32
 # define BSWAP32(x)  (__builtin_bswap32((x)))
 #endif
+#endif
 
 #ifdef _MSC_VER
 # define BSWAP16(x)  ((_byteswap_ushort((x) >> 16) << 16) | _byteswap_ushort((x)))
