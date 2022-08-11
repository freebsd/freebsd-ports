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
@@ -84,10 +93,12 @@
 #include "io-access.h"
 
 #if defined(__linux) || defined(__FreeBSD__) || ((defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__)))
+#if !defined(__aarch64__) && !defined (__aarch64__)
 
 #define IO_PORT_ACCESS
 
 static int io_fd = -1;
+#endif
 #endif
 
 #if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
