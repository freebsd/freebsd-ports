--- libgphoto2_port/serial/unix.c.orig	Mon May  2 14:36:52 2005
+++ libgphoto2_port/serial/unix.c	Mon Mar 13 16:35:59 2006
@@ -108,7 +108,11 @@
 
 /* FreeBSD */
 #ifdef __FreeBSD__
+#if __FreeBSD_version < 600000
 #define GP_PORT_SERIAL_PREFIX   "/dev/cuaa%x"
+#else
+#define GP_PORT_SERIAL_PREFIX   "/dev/cuad%x"
+#endif
 #define GP_PORT_SERIAL_RANGE_LOW        0
 #define GP_PORT_SERIAL_RANGE_HIGH       (0xf)
 #endif
