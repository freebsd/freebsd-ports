--- ./clitest.c.orig	2008-10-09 04:38:01.000000000 +0200
+++ ./clitest.c	2011-05-02 23:42:29.730543145 +0200
@@ -4,6 +4,7 @@
 #include <winsock2.h>
 #include <windows.h>
 #else
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #endif
