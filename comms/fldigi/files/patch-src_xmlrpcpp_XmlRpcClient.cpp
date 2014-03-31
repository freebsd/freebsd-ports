--- src/xmlrpcpp/XmlRpcClient.cpp.orig	2014-03-21 11:25:57.000000000 -0500
+++ src/xmlrpcpp/XmlRpcClient.cpp	2014-03-21 18:21:01.000000000 -0500
@@ -22,6 +22,7 @@
 // ----------------------------------------------------------------------------
 
 #include <config.h>
+#include <ios>
 
 #include "XmlRpcClient.h"
 
@@ -338,7 +339,7 @@
 
   header += "Content-Type: text/xml\r\nContent-length: ";
 
-  sprintf(buff,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buff,"%" PRIuSZ "\r\n\r\n", body.size());
 
   return header + buff;
 }
