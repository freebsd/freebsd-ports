--- sim/arm/skyeye_net_vnet.c.orig	Tue Mar  1 14:51:24 2005
+++ sim/arm/skyeye_net_vnet.c	Sat Jul 16 18:23:34 2005
@@ -26,6 +26,12 @@
  *				chenyu <chenyu@hpclab.cs.tsinghua.edu.cn>
  */
 #include <fcntl.h> 
+
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
+
+
 #include <net/if.h>
 //#include <linux/if_tun.h>
 #include <sys/ioctl.h>
