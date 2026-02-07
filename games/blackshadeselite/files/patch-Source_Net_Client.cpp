--- Source/Net/Client.cpp.orig	2007-11-22 01:14:15.000000000 +0300
+++ Source/Net/Client.cpp	2015-03-27 01:30:41.036397000 +0300
@@ -2,10 +2,8 @@
 
 #define SRV_IP "0.0.0.0"
 
-Client::Client()
+Client::Client() : NetCommon()
 {
-  NetCommon::NetCommon();
-
   memset((char *)&remote_sock, 0, sizeof(remote_sock));
   remote_sock.sin_family = AF_INET;
   remote_sock.sin_port = htons(port);
