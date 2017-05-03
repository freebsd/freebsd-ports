--- EMULib/Unix/NetUnix.c.orig	2009-12-17 07:37:54 UTC
+++ EMULib/Unix/NetUnix.c
@@ -20,6 +20,7 @@
 #include <errno.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 
 static int IsServer = 0;
 static int Socket   = -1;
