--- examples/parts/uart_pty.c.orig	2016-01-19 09:41:55 UTC
+++ examples/parts/uart_pty.c
@@ -30,8 +30,15 @@
 #ifdef __APPLE__
 #include <util.h>
 #else
+#ifdef FREEBSD
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#else
 #include <pty.h>
 #endif
+#endif
 
 #include "uart_pty.h"
 #include "avr_uart.h"
