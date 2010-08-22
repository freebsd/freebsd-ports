--- libpcsxcore/socket.c.orig	2010-05-19 17:43:40.987010639 +0000
+++ libpcsxcore/socket.c	2010-05-19 17:46:42.625194542 +0000
@@ -19,9 +19,11 @@
 #ifdef _WIN32
 #include <winsock2.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <unistd.h>
 #include <fcntl.h>
 #endif
