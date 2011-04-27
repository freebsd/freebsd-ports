--- ./clitest.c.orig	2008-10-09 04:38:01.000000000 +0200
+++ ./clitest.c	2011-04-27 14:03:12.956175470 +0200
@@ -4,6 +4,7 @@
 #include <winsock2.h>
 #include <windows.h>
 #else
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #endif
