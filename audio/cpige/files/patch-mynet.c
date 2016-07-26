--- mynet.c.orig	2006-08-20 14:51:17 UTC
+++ mynet.c
@@ -86,7 +86,7 @@ int server_connect (char *servername, in
 {
   struct sockaddr_in serverSockAddr;
   struct hostent *serverHostEnt;
-  long hostAddr;
+  in_addr_t hostAddr;
   
 #if WIN32
   int res;
@@ -105,7 +105,7 @@ int server_connect (char *servername, in
   hostAddr = inet_addr(servername); 
   
   /* If it is an ip address */
-  if ((long) hostAddr != (long)-1)
+  if ( hostAddr != INADDR_NONE ) 
     memcpy(&serverSockAddr.sin_addr, &hostAddr, sizeof(hostAddr));
   else {
     serverHostEnt = gethostbyname(servername);
