--- src/unix/joystick-drivers/joy_usb.c.orig	Sun Aug 22 15:31:47 2004
+++ src/unix/joystick-drivers/joy_usb.c	Sun Aug 22 15:32:30 2004
@@ -20,7 +20,7 @@
 };
 
 #ifdef USB_JOYSTICK
-
+#define __ARCH_freebsd
 #if !defined(__ARCH_netbsd) && !defined(__ARCH_freebsd)
 #error "USB joysticks are only supported under NetBSD and FreeBSD.  Patches to support other archs are welcome ;)"
 #endif
