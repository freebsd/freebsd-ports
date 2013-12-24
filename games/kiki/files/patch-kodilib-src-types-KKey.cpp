--- ./kodilib/src/types/KKey.cpp.orig	2003-04-09 06:56:05.000000000 +0400
+++ ./kodilib/src/types/KKey.cpp	2013-12-24 04:48:44.925583387 +0400
@@ -31,7 +31,7 @@
 // --------------------------------------------------------------------------------------------------------
 std::string KKey::getUnmodifiedName () const
 {
-    unsigned int keyPos = name.find('_', 0);
+    size_t keyPos = name.find('_', 0);
     if (keyPos == std::string::npos) 
     {
         return name;
@@ -42,7 +42,7 @@
 // --------------------------------------------------------------------------------------------------------
 std::string KKey::getModifierName () const
 {
-    unsigned int keyPos = name.find('_', 0);
+    size_t keyPos = name.find('_', 0);
     if (keyPos == std::string::npos) 
     {
         return "";
