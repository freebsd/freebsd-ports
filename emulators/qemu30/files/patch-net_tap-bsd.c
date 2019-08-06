--- net/tap-bsd.c.orig	2019-04-12 03:28:28 UTC
+++ net/tap-bsd.c
@@ -31,6 +31,7 @@
 
 #if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_tap.h>
 #endif
