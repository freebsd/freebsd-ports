--- src/arena.cpp.orig	Mon Nov  3 06:47:41 2003
+++ src/arena.cpp	Wed Nov  5 20:32:03 2003
@@ -64,11 +64,16 @@
 
 Vector<int> Arena::random_tile()
 {
+  const size_t ax = size.x - 2;
+  const size_t ay = size.y - 2;
+  const size_t av = ax * ay;
+
   Vector<int> t;
 
   do {
-    t.x = std::rand() % (size.x - 2) + 1;
-    t.y = std::rand() % (size.y - 2) + 1;
+    const int rnd = std::rand() % av;
+    t.x = rnd % ax + 1;
+    t.y = rnd / ax + 1;
   } while (occupier(t) != 0);
 
   return t;
