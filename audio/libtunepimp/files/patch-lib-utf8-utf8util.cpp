--- lib/utf8/utf8util.cpp.orig	2006-11-18 12:52:26.000000000 +0200
+++ lib/utf8/utf8util.cpp	2010-06-07 10:39:57.243921985 +0300
@@ -26,6 +26,7 @@
 ----------------------------------------------------------------------------*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "utf8util.h"
 #include "utf8.h"
 #ifdef WIN32
@@ -38,7 +39,7 @@ string utf8Encode(const string &from)
     char *dest;
     string to;
 
-    to.clear();
+    to = "";
     ret = utf8_encode(from.c_str(), &dest);
     if (ret >= 0)
     {
@@ -54,7 +55,7 @@ string utf8Decode(const string &from)
     char *dest;
     string to;
 
-    to.clear();
+    to = "";
     ret = utf8_decode(from.c_str(), &dest);
     if (ret >= 0)
     {
