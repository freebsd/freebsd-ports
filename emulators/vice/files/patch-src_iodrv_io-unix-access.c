--- src/iodrv/io-unix-access.c.orig	2022-01-24 00:13:24 UTC
+++ src/iodrv/io-unix-access.c
@@ -26,6 +26,15 @@
 
 #include "vice.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#if defined(__ppc__)
+#include <machine/pio.h>
+#else
+#include <machine/iodev.h>
+#endif
+#endif
+
 #ifdef UNIX_COMPILE
 
 #include <fcntl.h>
