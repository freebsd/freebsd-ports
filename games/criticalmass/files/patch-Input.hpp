--- game/Input.hpp.orig	Mon Aug 16 15:03:38 2004
+++ game/Input.hpp	Mon Aug 16 15:04:07 2004
@@ -28,7 +28,7 @@
 
 namespace HASH_NAMESPACE
 {
-    struct hash<Trigger>
+    template <> struct hash<Trigger>
     {
 	//a simple hash function for Trigger
 	int operator()(const Trigger &t) const
