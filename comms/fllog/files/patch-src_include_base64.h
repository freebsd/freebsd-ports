--- src/include/base64.h.orig	2014-04-11 13:41:47.000000000 -0700
+++ src/include/base64.h	2014-04-11 13:41:56.000000000 -0700
@@ -10,6 +10,7 @@
 #define __BASE64_H_INCLUDED__ 1
 
 #include <iterator>
+#include <ios>
 
 static
 int _base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
