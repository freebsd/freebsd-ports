--- src/xmlrpcpp/XmlRpcBase64.h.orig	2015-04-27 22:16:11.000000000 -0700
+++ src/xmlrpcpp/XmlRpcBase64.h	2015-04-27 22:16:22.000000000 -0700
@@ -18,6 +18,7 @@
 #if !defined(__BASE64_H_INCLUDED__)
 #define __BASE64_H_INCLUDED__ 1
 
+#include <ios>
 #include <iterator>
 
 static
