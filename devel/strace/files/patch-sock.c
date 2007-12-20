--- sock.c.orig	2007-12-20 16:31:01.000000000 +0000
+++ sock.c	2007-12-20 16:31:23.000000000 +0000
@@ -44,6 +44,7 @@
 #include <ioctls.h>
 #endif
 #endif
+#include <sys/socket.h>
 #include <net/if.h>
 
 extern struct xlat addrfams[];
