--- demo/ppmload.c.orig	2016-01-24 18:35:23 UTC
+++ demo/ppmload.c
@@ -30,6 +30,8 @@
 # include <machine/endian.h>
 # include <libkern/OSByteOrder.h>
 # define htobe16(x) OSSwapHostToBigInt16(x)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+# include <sys/endian.h>
 #else
 # include <endian.h>
 #endif
