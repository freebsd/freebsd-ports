--- src/xmlrpcpp/XmlRpcServer.cpp.orig	2014-03-21 11:25:57.000000000 -0500
+++ src/xmlrpcpp/XmlRpcServer.cpp	2014-03-21 18:21:06.000000000 -0500
@@ -500,7 +500,7 @@
     "Content-length: ";
 
   char buffLen[40];
-  sprintf(buffLen,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buffLen,"%" PRIuSZ" \r\n\r\n", body.size());
 
   return header + buffLen;
 }
