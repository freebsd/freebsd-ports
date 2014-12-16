--- src/ctrl/control_if.c.orig	2014-12-10 16:01:13.000000000 +0200
+++ src/ctrl/control_if.c	2014-12-10 16:01:43.000000000 +0200
@@ -32,6 +32,7 @@
 #include <arpa/inet.h>
 
 #include <netinet/tcp.h>
+#include <netinet/in.h>
 
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
