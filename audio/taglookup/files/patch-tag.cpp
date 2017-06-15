--- tag.cpp.orig	2007-10-28 22:42:56 UTC
+++ tag.cpp
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
@@ -166,8 +167,8 @@ namespace TagLookup
         
         bool operator() (const FileRefLengthPair &f1, const FileRefLengthPair &f2)
         {
-            if( abs(f1.second - x_) <
-                abs(f2.second - x_) )
+            if( abs((int)(f1.second - x_)) <
+                abs((int)(f2.second - x_)) )
                 return true;
             else
                 return false;
@@ -261,8 +262,14 @@ namespace TagLookup
         
         void operator() (const OldNameNewName &onnn)
         {
-            std::string new_base(basename(onnn.new_name.c_str()));
-            std::string new_path(dirname(onnn.old_name.c_str()));
+            std::vector<char> newbuf(onnn.new_name.begin(), onnn.new_name.end());
+            newbuf.push_back('\0');
+
+            std::vector<char> oldbuf(onnn.old_name.begin(), onnn.old_name.end());
+            oldbuf.push_back('\0');
+
+            std::string new_base(basename(newbuf.data()));
+            std::string new_path(dirname(oldbuf.data()));
             
             new_path.append("/");
             new_path.append(new_base);
