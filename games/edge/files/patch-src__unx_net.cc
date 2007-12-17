--- ./src/unx_net.cc.orig	Sat Nov 25 05:25:10 2006
+++ ./src/unx_net.cc	Wed Dec  5 23:19:09 2007
@@ -36,7 +36,11 @@
 #define htons  htons_FUCK
 
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <net/if.h>
+#else
 #include <linux/netdevice.h> 
+#endif
 
 // possible: <linux/if.h>
 //           <linux/sockios.h>
