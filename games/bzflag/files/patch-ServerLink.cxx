--- src/bzflag/ServerLink.cxx.orig	Sat Jan 26 09:26:30 2002
+++ src/bzflag/ServerLink.cxx	Sat Jan 26 09:25:55 2002
@@ -781,7 +781,7 @@
   if ((urecvfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
 	return; // we cannot comply
   }
-  for (int portno=17200; portno < 65000; portno++) {
+  for (int portno=49152; portno < 65535; portno++) {
   	::memset((unsigned char *)&serv_addr, 0, sizeof(serv_addr));
   	serv_addr.sin_family = AF_INET;
   	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
