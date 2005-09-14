--- lib/utf8/utf8util.cpp.orig	Mon Jul 11 05:01:23 2005
+++ lib/utf8/utf8util.cpp	Wed Sep 14 17:19:42 2005
@@ -38,7 +38,7 @@
     char *dest;
     string to;
 
-    to.clear();
+    to = "";
     ret = utf8_encode(from.c_str(), &dest);
     if (ret >= 0)
     {
@@ -54,7 +54,7 @@
     char *dest;
     string to;
 
-    to.clear();
+    to = "";
     ret = utf8_decode(from.c_str(), &dest);
     if (ret >= 0)
     {
