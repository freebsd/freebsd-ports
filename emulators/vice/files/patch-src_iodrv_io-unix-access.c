--- src/iodrv/io-unix-access.c.orig	2019-03-21 09:04:15 UTC
+++ src/iodrv/io-unix-access.c
@@ -26,6 +26,11 @@
 
 #include "vice.h"
 
+#if defined(__FreeBSD__) && defined(__ppc__)
+#include <sys/types.h>
+#include <machine/pio.h>
+#endif
+
 #ifdef UNIX_COMPILE
 
 #include <fcntl.h>
