--- src/gallium/drivers/r600/r600_shader.c.orig	2013-05-16 19:38:54.000000000 +0200
+++ src/gallium/drivers/r600/r600_shader.c	2013-06-26 23:26:02.000000000 +0200
@@ -35,7 +35,12 @@
 #include "util/u_memory.h"
 #include <stdio.h>
 #include <errno.h>
+#if defined(__linux__)
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x)	bswap32((x))
+#endif
 
 /* CAYMAN notes 
 Why CAYMAN got loops for lots of instructions is explained here.
