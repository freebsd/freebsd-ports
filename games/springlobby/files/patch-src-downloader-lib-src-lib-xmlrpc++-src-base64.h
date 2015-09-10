--- src/downloader/lib/src/lib/xmlrpc++/src/base64.h.orig	2013-02-10 22:02:43.000000000 +0400
+++ src/downloader/lib/src/lib/xmlrpc++/src/base64.h	2013-12-10 04:19:12.257112752 +0400
@@ -13,6 +13,8 @@
 # include <iterator>
 #endif
 
+#include <iostream>
+
 static
 int _base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
 				     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
