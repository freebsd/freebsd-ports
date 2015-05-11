--- src/xmlrpcpp/XmlRpcBase64.h.orig	2015-04-28 12:53:47.291010000 -0400
+++ src/xmlrpcpp/XmlRpcBase64.h	2015-04-28 12:53:56.470160000 -0400
@@ -18,6 +18,7 @@
 #if !defined(__BASE64_H_INCLUDED__)
 #define __BASE64_H_INCLUDED__ 1
 
+#include <ios>
 #include <iterator>
 
 static
