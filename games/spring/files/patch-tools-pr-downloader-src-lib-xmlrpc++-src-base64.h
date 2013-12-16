--- tools/pr-downloader/src/lib/xmlrpc++/src/base64.h.orig	2013-03-26 03:58:49.000000000 +0400
+++ tools/pr-downloader/src/lib/xmlrpc++/src/base64.h	2013-11-09 14:42:21.013340982 +0400
@@ -13,6 +13,8 @@
 # include <iterator>
 #endif
 
+#include <ios>
+
 static
 int _base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
 				     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
