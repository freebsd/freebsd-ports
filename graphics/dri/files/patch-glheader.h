--- src/mesa/main/glheader.h.orig	Thu Apr 13 01:52:32 2006
+++ src/mesa/main/glheader.h	Wed Dec 20 15:27:53 2006
@@ -127,12 +127,15 @@
  * For now, only used by some DRI hardware drivers for color/texel packing.
  */
 #if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN
-#if defined(__linux__)
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
+#elif defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
-#else /*__linux__*/
-#define CPU_TO_LE32( x )	( x )  /* fix me for non-Linux big-endian! */
-#endif /*__linux__*/
+#else
+#error "Add CPU_TO_LE32 macro for this OS."
+#endif
 #define MESA_BIG_ENDIAN 1
 #else
 #define CPU_TO_LE32( x )	( x )
