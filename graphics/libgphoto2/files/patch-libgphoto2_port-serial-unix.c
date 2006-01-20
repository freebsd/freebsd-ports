--- libgphoto2_port/serial/unix.c.orig	Wed Jan 18 18:06:35 2006
+++ libgphoto2_port/serial/unix.c	Wed Jan 18 18:08:39 2006
@@ -108,7 +108,11 @@
 
 /* FreeBSD */
 #if defined(__FreeBSD__)
+#if __FreeBSD_version < 600000
 #define GP_PORT_SERIAL_PREFIX   "/dev/cuaa%x"
+#else
+#define GP_PORT_SERIAL_PREFIX   "/dev/cuad%x"
+#endif
 #define GP_PORT_SERIAL_RANGE_LOW        0
 #define GP_PORT_SERIAL_RANGE_HIGH       (0xf)
 #endif
