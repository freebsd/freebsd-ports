--- src/xmlrpcpp/XmlRpcClient.cpp.orig	2013-11-19 10:11:37.383366764 -0500
+++ src/xmlrpcpp/XmlRpcClient.cpp	2013-11-19 10:13:43.795365774 -0500
@@ -3,6 +3,7 @@
 //
 
 #include <config.h>
+#include <ios>
 
 #include "XmlRpcClient.h"
 
@@ -319,7 +320,7 @@
 
   header += "Content-Type: text/xml\r\nContent-length: ";
 
-  sprintf(buff,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buff,"%" PRIuSZ "\r\n\r\n", body.size());
 
   return header + buff;
 }
