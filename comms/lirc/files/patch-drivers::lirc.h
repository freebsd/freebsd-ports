--- drivers/lirc.h.orig	Sun Aug 21 21:45:04 2005
+++ drivers/lirc.h	Sun Aug 21 21:45:11 2005
@@ -8,6 +8,7 @@
 #include <linux/ioctl.h>
 #else
 #include <sys/types.h>
+#include <sys/ioctl.h>
 typedef u_int32_t __u32;
 #endif
 
