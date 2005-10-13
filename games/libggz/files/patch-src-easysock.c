--- src/easysock.c.orig	Mon Sep 19 01:28:42 2005
+++ src/easysock.c	Fri Oct  7 12:45:11 2005
@@ -49,8 +49,8 @@
 #include <sys/uio.h>
 #include <sys/un.h>
 #include <sys/param.h>
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 
 #ifdef HAVE_WINSOCK2_H
