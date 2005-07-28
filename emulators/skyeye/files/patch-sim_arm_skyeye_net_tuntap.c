--- sim/arm/skyeye_net_tuntap.c.orig	Tue Mar  1 14:51:24 2005
+++ sim/arm/skyeye_net_tuntap.c	Sat Jul 16 18:22:57 2005
@@ -26,8 +26,19 @@
  *				chenyu <chenyu@hpclab.cs.tsinghua.edu.cn>
  */
  
+#ifdef __linux__
 #include <net/if.h>
 #include <linux/if_tun.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_tun.h>
+#include <fcntl.h>
+#endif
+
+
 #include <sys/ioctl.h>
 #include "armdefs.h"
 
@@ -51,7 +62,7 @@
   DBG_PRINT("tapif_init begin\n");
   
   firsttime++;
-  
+#ifdef __linux__  
   //tapif_fd = open("/dev/net/tun", O_RDWR);
   tapif_fd = open("/dev/net/tun", 2);
   DBG_PRINT("tapif_init: fd %d\n", tapif_fd);
@@ -68,13 +79,36 @@
     exit(1);
     //return ;
   }
+#endif
 
+#ifdef __FreeBSD__
+  tapif_fd = open("/dev/tap", O_RDWR);
+  DBG_PRINT("tapif_init: fd %d\n", tapif_fd);
+  if(tapif_fd == -1) {
+    perror("tapif_init:open");
+    printf("-----------------------------------------------------------\n");
+    printf("NOTICE: You should run as root if you require network\n");
+    printf("NOTICE: load the kernel tap module with 'kldload if_tap'\n");
+    printf("NOTICE: and execute 'cat /dev/tap'. there should be a \n");
+    printf("NOTICE: device node under /dev/ (e.g. /dev/tap0).\n");
+    printf("-----------------------------------------------------------\n");
+    exit(1);
+  }
+#endif
+
+#if !defined(__FreeBSD__)&&!defined(__linux__)
+    printf("NOTICE: No network support for your OS(yet). Bugging out!\n");
+    exit(1);
+#endif
+
+#ifndef __FreeBSD__
   memset(&ifr, 0, sizeof(ifr));
   ifr.ifr_flags = IFF_TAP|IFF_NO_PI;
   if (ioctl(tapif_fd, TUNSETIFF, (void *) &ifr) < 0) {
     perror("tapif_init: icotl TUNSETIFF error");
     exit(-1);
   }
+#endif
 
   if(firsttime==1){
       snprintf(buf, sizeof(buf), "ifconfig tap0 inet %d.%d.%d.%d",
