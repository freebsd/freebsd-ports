--- sim/arm/skyeye-ne2k.c.orig	Tue Mar  1 14:51:24 2005
+++ sim/arm/skyeye-ne2k.c	Sat Jul 16 18:17:14 2005
@@ -26,13 +26,23 @@
  * 02/25/2003 	initial version
  *				yangye <yangye@163.net> 		
  */
- 
+#ifdef __linux__ 
 //#include <linux/if.h>
 #include <net/if.h>
 #include <linux/if_tun.h>
 //#include <sys/types.h>
 //#include <sys/stat.h>
 //#include <fcntl.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_tun.h>
+#endif
+
+
 #include <sys/ioctl.h>
 #include <armdefs.h>
 #include <clps7110.h>
