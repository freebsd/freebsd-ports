--- src/arch/shared/iodrv/io-unix-access.c.orig	2022-12-24 19:44:57 UTC
+++ src/arch/shared/iodrv/io-unix-access.c
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
