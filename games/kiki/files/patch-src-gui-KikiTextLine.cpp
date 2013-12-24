--- ./src/gui/KikiTextLine.cpp.orig	2005-10-02 18:07:54.000000000 +0400
+++ ./src/gui/KikiTextLine.cpp	2013-12-24 04:48:17.413608892 +0400
@@ -46,7 +46,7 @@
 void KikiTextLine::setText ( const std::string & str )
 {
     text = str;
-    unsigned int pos;
+    size_t pos;
  
     if ((pos = text.find ("$scale(")) != std::string::npos)
     {
