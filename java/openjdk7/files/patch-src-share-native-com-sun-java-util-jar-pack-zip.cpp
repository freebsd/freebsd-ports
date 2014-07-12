--- jdk/src/share/native/com/sun/java/util/jar/pack/zip.cpp.orig	2014-07-12 09:24:56.000000000 -0700
+++ jdk/src/share/native/com/sun/java/util/jar/pack/zip.cpp	2014-07-12 09:28:38.000000000 -0700
@@ -33,6 +33,10 @@
 
 #include <stdlib.h>
 
+#ifdef _ALLBSD_SOURCE
+#include <machine/endian.h>
+#endif
+
 #ifndef _MSC_VER
 #include <strings.h>
 #endif
@@ -62,7 +66,7 @@
 
 #endif // End of ZLIB
 
-#ifdef _BIG_ENDIAN
+#if (BYTE_ORDER == BIG_ENDIAN)
 #define SWAP_BYTES(a) \
     ((((a) << 8) & 0xff00) | 0x00ff) & (((a) >> 8) | 0xff00)
 #else
