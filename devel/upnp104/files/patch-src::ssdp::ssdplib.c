--- src/ssdp/ssdplib.c.orig	Thu Aug 16 02:17:31 2001
+++ src/ssdp/ssdplib.c	Sat Aug  3 16:29:39 2002
@@ -403,7 +403,7 @@
     bzero((char *)&SelfAddr, sizeof(struct sockaddr_in));
 
     SelfAddr.sin_family = AF_INET;
-    SelfAddr.sin_addr.s_addr = inet_addr(SSDP_IP);
+    SelfAddr.sin_addr.s_addr = htonl(INADDR_ANY);
     SelfAddr.sin_port = htons(SSDP_PORT);
     if (bind( SsdpSock, (struct sockaddr *) &SelfAddr, sizeof(SelfAddr)) != 0)
     {
