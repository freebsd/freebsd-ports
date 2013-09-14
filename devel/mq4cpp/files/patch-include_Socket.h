--- include/Socket.h.orig	2013-09-14 18:46:04.000000000 +0800
+++ include/Socket.h	2013-09-14 18:46:17.000000000 +0800
@@ -30,6 +30,8 @@
 #else
 #include <netinet/in.h>
 #include <sys/socket.h>
+#include <sys/select.h>
+#include <unistd.h>
 typedef int SOCKET;
 #endif
 
