--- utils/HashString.hpp.orig	Tue Aug 17 16:17:33 2004
+++ utils/HashString.hpp	Tue Aug 17 16:18:12 2004
@@ -21,7 +21,7 @@
 
 namespace HASH_NAMESPACE
 {
-    struct hash<const string>
+    template <> struct hash<const string>
     {
 	//a simple hash function for string
 	int operator()(const string & s) const
@@ -32,7 +32,7 @@
 	}
     };
 
-    struct hash<string>
+    template <> struct hash<string>
     {
 	//a simple hash function for string
 	int operator()(string s) const
