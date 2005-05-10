--- src/misc_python.cpp.orig	Wed Apr 20 00:55:42 2005
+++ src/misc_python.cpp	Wed May 11 00:05:48 2005
@@ -385,6 +385,9 @@
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 /* now a method we need to expose to Python */
 QString getIp(char *device_name)
@@ -435,7 +438,7 @@
     /* devptr points into an array of ifreq structs. */
     devptr = &ifc_conf.ifc_req[i];
 
-    if (devptr->ifr_addr.sa_family != AF_INET)
+    if (ioctl(sd, SIOCGIFADDR, devptr) < 0 || devptr->ifr_addr.sa_family != AF_INET)
     continue;
 
     if (ioctl(sd,SIOCGIFFLAGS,devptr) < 0)
