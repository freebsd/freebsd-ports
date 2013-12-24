--- kodilib/src/tools/KStringTools.cpp.orig	2003-04-14 01:42:13.000000000 +0400
+++ kodilib/src/tools/KStringTools.cpp	2013-12-24 05:02:41.644525164 +0400
@@ -13,7 +13,7 @@
 void kStringInsertStringBehindTags ( std::string & str, const std::string & insertString, 
                                      const std::string & tag )
 {
-    unsigned int oldPos = 0;
+    size_t oldPos = 0;
     while ((oldPos = str.find(tag, oldPos)) != std::string::npos)
     {
         oldPos += tag.size();
@@ -34,8 +34,8 @@
 {
     std::vector<std::string> components;
     
-    unsigned int dividerLength = divider.size();
-    unsigned int oldpos = 0, pos;
+    size_t dividerLength = divider.size();
+    size_t oldpos = 0, pos;
     
     while ((pos = str.find(divider, oldpos)) != std::string::npos)
     {
@@ -50,7 +50,7 @@
 // --------------------------------------------------------------------------------------------------------
 void kStringReplace ( std::string & str, const std::string & toReplace, const std::string & replacement )
 {
-    unsigned int pos = 0, chars = toReplace.size();
+    size_t pos = 0, chars = toReplace.size();
     while ((pos = str.find(toReplace, pos)) != std::string::npos)
     {
         str.replace(pos, chars, replacement);
@@ -60,11 +60,11 @@
 // --------------------------------------------------------------------------------------------------------
 void kStringReplaceTabs ( std::string & str, unsigned int tabWidth )
 {
-    unsigned int tabPos;
+    size_t tabPos;
     while ((tabPos = str.find('\t')) != std::string::npos)
     {
-        unsigned int lastNewlinePos = str.rfind('\n', tabPos-1);
-        unsigned int relPos = (lastNewlinePos == std::string::npos) ? tabPos : tabPos - lastNewlinePos; 
+        size_t lastNewlinePos = str.rfind('\n', tabPos-1);
+        size_t relPos = (lastNewlinePos == std::string::npos) ? tabPos : tabPos - lastNewlinePos; 
         str.replace(tabPos, 1, std::string(tabWidth-(relPos % tabWidth), ' '));
     }
 }
@@ -114,7 +114,7 @@
 // --------------------------------------------------------------------------------------------------------
 unsigned int kStringNthCharPos ( const std::string & str, unsigned int n, char c )
 {
-    unsigned int loc = n, oloc = 0;
+    size_t loc = n, oloc = 0;
     while (n > 0 && (loc = str.find(c, oloc)) != std::string::npos)
     { 
         n--; 
@@ -138,7 +138,7 @@
 // --------------------------------------------------------------------------------------------------------
 void kStringCropCols ( std::string & str, unsigned int columns )
 {        
-    unsigned int oloc = 0, nloc = 0;
+    size_t oloc = 0, nloc = 0;
     while ((nloc = str.find('\n', oloc)) != std::string::npos)
     {
         if ((nloc - oloc) > columns)
@@ -160,10 +160,10 @@
 unsigned int kStringCols ( const std::string & str )
 {
     if (str.size() == 0) return 0;
-    int oloc = 0, nloc;
+    size_t oloc = 0, nloc;
     std::string substring;
-    int maxlength = 0, length;
-    while ((nloc = str.find('\n', oloc)) != (int)std::string::npos) 
+    size_t maxlength = 0, length;
+    while ((nloc = str.find('\n', oloc)) != std::string::npos) 
     {
         substring = str.substr(oloc, nloc - oloc);
         length = substring.size();
@@ -181,7 +181,7 @@
 unsigned int kStringRows ( const std::string & str )
 {
     if (str.size() == 0) return 1;
-    unsigned int loc = 0, lines = 0;
+    size_t loc = 0, lines = 0;
     while ((loc = str.find('\n', loc)) != std::string::npos) { lines++; loc++; }
     if (str[str.size()-1] == '\n') return lines;
     return lines+1;
@@ -204,8 +204,8 @@
 {
     static char str[256];
     std::string format(fmt), subformat, text;
-    unsigned int oloc = 0;
-    unsigned int nloc = 0;
+    size_t oloc = 0;
+    size_t nloc = 0;
     
     kStringReplaceTabs(format);
     
@@ -260,7 +260,7 @@
 // --------------------------------------------------------------------------------------------------------
 bool kStringHasSuffix ( const std::string & str, const std::string & suffix )
 {
-    unsigned int result = str.rfind(suffix);
+    size_t result = str.rfind(suffix);
     if (result == std::string::npos) return false;
     return (result == str.size()-suffix.size());
 }
