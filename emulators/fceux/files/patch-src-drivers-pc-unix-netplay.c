--- src/drivers/pc/unix-netplay.c.orig	Sun May 16 22:28:06 2004
+++ src/drivers/pc/unix-netplay.c	Tue May 18 12:57:05 2004
@@ -24,7 +24,7 @@
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
@@ -42,6 +42,8 @@
 #ifndef socklen_t
 #define socklen_t int
 #endif
+
+#define SOL_TCP IPPROTO_TCP
 
 char *netplayhost=0;
 char *netplaynick=0;
