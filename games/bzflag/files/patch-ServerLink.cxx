--- src/bzflag/ServerLink.cxx.orig	Sun Apr 15 13:32:03 2001
+++ src/bzflag/ServerLink.cxx	Sun Apr 15 13:32:20 2001
@@ -761,7 +761,7 @@
   if ((urecvfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
 	return; // we cannot comply
   }
-  for (int portno=17200; portno < 65000; portno++) {
+  for (int portno=49152; portno < 65535; portno++) {
   	bzero((unsigned char *)&serv_addr, sizeof(serv_addr)); 
   	serv_addr.sin_family = AF_INET;
   	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
