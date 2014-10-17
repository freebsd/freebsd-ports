--- src/mesa/main/compiler.h.orig	2013-04-06 04:01:09.000000000 +0200
+++ src/mesa/main/compiler.h	2013-06-26 23:26:02.000000000 +0200
@@ -171,6 +171,9 @@
 #if defined(__linux__)
 #include <byteswap.h>
 #define CPU_TO_LE32( x )	bswap_32( x )
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE32( x )	bswap32( x )
 #elif defined(__APPLE__)
 #include <CoreFoundation/CFByteOrder.h>
 #define CPU_TO_LE32( x )	CFSwapInt32HostToLittle( x )
