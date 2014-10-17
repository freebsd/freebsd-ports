--- ./src/mesa/main/compiler.h.orig	2014-01-23 18:02:42.000000000 +0100
+++ ./src/mesa/main/compiler.h	2014-02-23 22:01:50.000000000 +0100
@@ -162,6 +162,9 @@
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
 #elif defined(__APPLE__)
 #include <CoreFoundation/CFByteOrder.h>
 #define CPU_TO_LE32( x )	CFSwapInt32HostToLittle( x )
