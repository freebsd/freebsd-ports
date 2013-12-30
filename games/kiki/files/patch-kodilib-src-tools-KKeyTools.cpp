--- ./kodilib/src/tools/KKeyTools.cpp.orig	2003-04-09 06:56:03.000000000 +0400
+++ ./kodilib/src/tools/KKeyTools.cpp	2013-12-24 04:49:24.796993556 +0400
@@ -170,7 +170,7 @@
 // --------------------------------------------------------------------------------------------------------
 int kKeyGetDisplayWidthForKey ( const std::string & keyName )
 {
-    unsigned int keyPos = keyName.find('_', 0);
+    size_t keyPos = keyName.find('_', 0);
     if (keyPos == std::string::npos) 
     {
         return kKeyGetDisplayWidthForPureKey(keyName) + KDL_MOD_KEY_SPACING;
@@ -313,7 +313,7 @@
 int kKeyDisplayKey ( const std::string & keyName, const KPosition & pos )
 {
     KPosition start = pos;
-    unsigned int keyPos = keyName.find('_', 0);
+    size_t keyPos = keyName.find('_', 0);
     if (keyPos == std::string::npos) 
     {
         return start.x + kKeyDisplayPureKey(keyName, start) + KDL_MOD_KEY_SPACING;
@@ -380,7 +380,7 @@
 // --------------------------------------------------------------------------------------------------------
 SDL_keysym kKeyGetKeysymForKeyName ( const std::string & keyName )
 {
-    unsigned int pos = keyName.find('_');
+    size_t pos = keyName.find('_');
     
     std::string modString;
     std::string symString = keyName;
