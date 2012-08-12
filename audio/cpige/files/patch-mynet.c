--- ./mynet.c.orig	2006-08-20 17:51:17.000000000 +0300
+++ ./mynet.c	2012-08-12 12:29:05.000000000 +0300
@@ -86,7 +86,7 @@
 {
   struct sockaddr_in serverSockAddr;
   struct hostent *serverHostEnt;
-  long hostAddr;
+  in_addr_t hostAddr;
   
 #if WIN32
   int res;
@@ -105,7 +105,7 @@
   hostAddr = inet_addr(servername); 
   
   /* If it is an ip address */
-  if ((long) hostAddr != (long)-1)
+  if ( hostAddr != INADDR_NONE ) 
     memcpy(&serverSockAddr.sin_addr, &hostAddr, sizeof(hostAddr));
   else {
     serverHostEnt = gethostbyname(servername);
