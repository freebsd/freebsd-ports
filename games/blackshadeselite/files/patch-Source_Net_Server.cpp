--- Source/Net/Server.cpp.orig	2007-11-22 01:14:15.000000000 +0300
+++ Source/Net/Server.cpp	2015-03-27 01:30:50.356180000 +0300
@@ -1,9 +1,7 @@
 #include "Server.h"
 
-Server::Server()
+Server::Server() : NetCommon()
 {
-  NetCommon::NetCommon();
-
   memset((char *) &local_sock, 0, sizeof(local_sock));
   local_sock.sin_family = AF_INET;
   local_sock.sin_port = htons(PORT);
