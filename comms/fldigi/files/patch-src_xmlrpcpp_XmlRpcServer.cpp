--- src/xmlrpcpp/XmlRpcServer.cpp.orig	2013-11-19 10:16:57.123343807 -0500
+++ src/xmlrpcpp/XmlRpcServer.cpp	2013-11-19 10:17:23.150721491 -0500
@@ -481,7 +481,7 @@
     "Content-length: ";
 
   char buffLen[40];
-  sprintf(buffLen,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buffLen,"%" PRIuSZ" \r\n\r\n", body.size());
 
   return header + buffLen;
 }
