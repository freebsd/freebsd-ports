--- src/drivers/pc/unix-netplay.c.orig	Mon May 17 07:28:06 2004
+++ src/drivers/pc/unix-netplay.c	Fri May 21 10:20:13 2004
@@ -24,7 +24,7 @@
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
@@ -43,6 +43,8 @@
 #define socklen_t int
 #endif
 
+#define SOL_TCP IPPROTO_TCP
+
 char *netplayhost=0;
 char *netplaynick=0;
 char *netgamekey = 0;
@@ -76,7 +78,8 @@
  unsigned long hadr;
  int TSocket;
  int netdivisor;
-  
+ int tcpopt = 1;
+
  if(!netplayhost) return(0);
 
  if( (TSocket=socket(AF_INET,SOCK_STREAM,0))==-1)
@@ -85,7 +88,6 @@
   FCEUD_NetworkClose();
   return(0);
  }
- int tcpopt = 1;  
  if(setsockopt(TSocket, SOL_TCP, TCP_NODELAY, &tcpopt, sizeof(int)))
   puts("Nodelay fail");
 
