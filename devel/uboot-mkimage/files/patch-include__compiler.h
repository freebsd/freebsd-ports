--- ./include/compiler.h.orig	2010-12-22 21:22:14.000000000 +0200
+++ ./include/compiler.h	2011-01-13 13:50:35.000000000 +0200
@@ -44,7 +44,7 @@
 #ifdef __linux__
 # include <endian.h>
 # include <byteswap.h>
-#elif defined(__MACH__)
+#elif defined(__MACH__) || defined(__FreeBSD__)
 # include <machine/endian.h>
 typedef unsigned long ulong;
 #endif
