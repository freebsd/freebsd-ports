--- src/unix/video-drivers/svgainput.c.orig	Tue Oct 16 11:06:30 2001
+++ src/unix/video-drivers/svgainput.c	Tue Oct 16 11:05:37 2001
@@ -12,6 +12,10 @@
 #include "devices.h"
 #include "keyboard.h"
 
+#ifdef __FreeBSD__
+#define	SIGUNUSED	SIGUSR2
+#endif
+
 static int console_fd       = -1;
 static int mouse_fd         = -1;
 static int leds             =  0;
