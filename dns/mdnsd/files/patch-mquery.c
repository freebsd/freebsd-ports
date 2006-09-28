diff -ruN mquery.c.orig mquery.c
--- mquery.c.orig	Tue Feb 18 08:59:49 2003
+++ mquery.c	Mon Sep 25 22:11:18 2006
@@ -1,21 +1,29 @@
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <stdio.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <stdlib.h>
+#include <string.h>
+#include <strings.h>
+#include <unistd.h>
 
 #include "mdnsd.h"
 
 // print an answer
 int ans(mdnsda a, void *arg)
 {
+    struct in_addr ip;
     int now;
+    ip.s_addr = a->ip;
     if(a->ttl == 0) now = 0;
     else now = a->ttl - time(0);
     switch(a->type)
     {
     case QTYPE_A:
-        printf("A %s for %d seconds to ip %s\n",a->name,now,inet_ntoa(a->ip));
+        printf("A %s for %d seconds to ip %s\n",a->name,now,inet_ntoa(ip));
         break;
     case QTYPE_PTR:
         printf("PTR %s for %d seconds to %s\n",a->name,now,a->rdname);
@@ -26,6 +34,7 @@
     default:
         printf("%d %s for %d seconds with %d data\n",a->type,a->name,now,a->rdlen);
     }
+    return 0;
 }
 
 // create multicast 224.0.0.251:5353 socket
@@ -74,7 +83,7 @@
     fd_set fds;
     int s;
 
-    if(argc != 3) { printf("usage: mquery 12 _http._tcp.local.\n"); return; }
+    if(argc != 3) { printf("usage: mquery 12 _http._tcp.local.\n"); return 0; }
 
     d = mdnsd_new(1,1000);
     if((s = msock()) == 0) { printf("can't create socket: %s\n",strerror(errno)); return 1; }
