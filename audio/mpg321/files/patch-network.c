
$FreeBSD$

--- network.c.orig	Mon Sep 24 16:01:09 2001
+++ network.c	Mon Sep 24 16:01:27 2001
@@ -237,7 +237,7 @@
   int data_sock;
   char ftp_request[1024];
   struct sockaddr_in stLclAddr;
-  size_t namelen;
+  socklen_t namelen;
   int i;
 
   /* Check for URL syntax */
