--- net/tap-bsd.c.orig	2015-11-03 20:01:34 UTC
+++ net/tap-bsd.c
@@ -29,6 +29,7 @@
 
 #if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_tap.h>
 #endif
