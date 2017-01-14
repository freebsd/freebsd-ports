--- src/arch/unix/io-access.c.orig	2016-11-17 19:06:26 UTC
+++ src/arch/unix/io-access.c
@@ -77,7 +77,7 @@
 #include "log.h"
 #include "types.h"
 
-#if defined(__linux) || defined(__FreeBSD__) || ((defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__)))
+#if defined(__linux) || ((defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__)))
 
 #define IO_PORT_ACCESS
 
@@ -162,7 +162,7 @@ static void device_io_outb(WORD addr, BY
 }
 #endif
 
-#ifdef __FreeBSD__
+#if 0
 static int device_io_open(void)
 {
     io_fd = open("/dev/io", O_RDWR);
