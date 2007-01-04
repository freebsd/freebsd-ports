--- include/Socket.h.orig	Mon Dec 18 02:57:52 2006
+++ include/Socket.h	Thu Jan  4 12:26:33 2007
@@ -29,6 +29,7 @@
 #include <WinSock2.h>
 #else
 #include <netinet/in.h>
+#include <sys/socket.h>
 typedef int SOCKET;
 #endif
 
