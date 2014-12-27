--- src/xmlrpcpp/base64.h.orig	2014-12-10 08:23:34.000000000 -0500
+++ src/xmlrpcpp/base64.h	2014-12-27 11:45:05.000000000 -0500
@@ -28,6 +28,7 @@
 #define __BASE64_H_INCLUDED__ 1
 
 #include <iterator>
+#include <ios>
 
 static
 int _base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
