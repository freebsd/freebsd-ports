--- src/api/upnpapi.c.orig	Fri Jun 15 08:22:15 2001
+++ src/api/upnpapi.c	Sat Aug  3 16:29:38 2002
@@ -44,7 +44,7 @@
 #include<string.h>
 
 #include <sys/ioctl.h>
-#include <linux/if.h>
+#include <net/if.h>
 #include <sys/utsname.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
