--- src/xmlrpcpp/XmlRpcBase64.h.orig	2015-04-23 11:39:24 UTC
+++ src/xmlrpcpp/XmlRpcBase64.h
@@ -18,6 +18,7 @@
 #if !defined(__BASE64_H_INCLUDED__)
 #define __BASE64_H_INCLUDED__ 1
 
+#include <ios>
 #include <iterator>
 
 static
