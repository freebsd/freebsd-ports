--- src/unix/video-drivers/svgainput.c.orig	Fri May  3 02:53:54 2002
+++ src/unix/video-drivers/svgainput.c	Thu Oct 31 12:46:04 2002
@@ -12,6 +12,10 @@
 #include "devices.h"
 #include "keyboard.h"
 
+#if defined(__ARCH_freebsd)
+#define	SIGUNUSED	SIGUSR2
+#endif
+
 static int console_fd       = -1;
 static int mouse_fd         = -1;
 static int leds             =  0;
