--- utils/HashString.hpp.orig	Mon Aug 16 15:01:21 2004
+++ utils/HashString.hpp	Mon Aug 16 15:02:23 2004
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
