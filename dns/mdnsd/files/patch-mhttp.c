diff -ruN mhttp.c.orig mhttp.c
--- mhttp.c.orig	Tue Feb 18 08:54:56 2003
+++ mhttp.c	Mon Sep 25 22:11:17 2006
@@ -1,9 +1,16 @@
+#include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/uio.h>
 #include <netinet/in.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <signal.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <strings.h>
+#include <unistd.h>
 
 #include "mdnsd.h"
 #include "sdtxt.h"
@@ -64,7 +71,8 @@
     mdnsd d;
     mdnsdr r;
     struct message m;
-    unsigned long int ip;
+    //unsigned long int ip;
+    struct in_addr ip;
     unsigned short int port;
     struct timeval *tv;
     int bsize, ssize = sizeof(struct sockaddr_in);
@@ -76,9 +84,9 @@
     int len = 0;
     xht h;
 
-    if(argc < 4) { printf("usage: mhttp 'unique name' 12.34.56.78 80 '/optionalpath'\n"); return; }
+    if(argc < 4) { printf("usage: mhttp 'unique name' 12.34.56.78 80 '/optionalpath'\n"); return 0; }
 
-    ip = inet_addr(argv[2]);
+    ip.s_addr = inet_addr(argv[2]);
     port = atoi(argv[3]);
     printf("Announcing .local site named '%s' to %s:%d and extra path '%s'\n",argv[1],inet_ntoa(ip),port,argv[4]);
 
@@ -127,12 +135,12 @@
             }
             if(bsize < 0 && errno != EAGAIN) { printf("can't read from socket %d: %s\n",errno,strerror(errno)); return 1; }
         }
-        while(mdnsd_out(d,&m,&ip,&port))
+        while(mdnsd_out(d,&m,(unsigned long int *)&(ip.s_addr),&port))
         {
             bzero(&to, sizeof(to));
             to.sin_family = AF_INET;
             to.sin_port = port;
-            to.sin_addr.s_addr = ip;
+            to.sin_addr.s_addr = ip.s_addr;
             if(sendto(s,message_packet(&m),message_packet_len(&m),0,(struct sockaddr *)&to,sizeof(struct sockaddr_in)) != message_packet_len(&m))  { printf("can't write to socket: %s\n",strerror(errno)); return 1; }
         }
         if(_shutdown) break;
