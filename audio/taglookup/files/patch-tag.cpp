--- ./tag.cpp.orig	2007-10-28 18:42:56.000000000 -0400
+++ ./tag.cpp	2011-03-18 18:59:23.000000000 -0400
@@ -27,6 +27,7 @@
 #include <utility>
 
 #include <ostream>
+#include <iostream>
 
 // LibC TODO Replace with STL
 // POSIX
@@ -49,9 +50,9 @@
 namespace TagLookup
 {
     // Utility functions:
-    const TagLib::String::String toUTF8String(const std::string& s)
+    const TagLib::String toUTF8String(const std::string& s)
     {
-        const TagLib::String::String new_string(s, TagLib::String::UTF8);
+        const TagLib::String new_string(s, TagLib::String::UTF8);
         
         return new_string;
     } // toUTF8String
