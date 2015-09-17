--- src/mesa/main/compiler.h.orig	2015-06-07 06:45:48.000000000 -0400
+++ src/mesa/main/compiler.h	2015-06-16 05:04:53.967546000 -0400
@@ -70,6 +70,9 @@
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
 #elif defined(__APPLE__)
 #include <CoreFoundation/CFByteOrder.h>
 #define CPU_TO_LE32( x )	CFSwapInt32HostToLittle( x )
