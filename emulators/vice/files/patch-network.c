--- src/network.c.orig	Sat Nov 19 15:36:06 2005
+++ src/network.c	Sat Dec  3 17:38:37 2005
@@ -35,8 +35,8 @@
 #ifdef WIN32
 #include <winsock.h>
 #else
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
