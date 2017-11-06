--- src/bunnysay.cc.orig	2017-02-28 03:26:39 UTC
+++ src/bunnysay.cc
@@ -99,7 +99,7 @@ void fullWidth(std::vector<std::vector<R
 }
 
 void padTo(std::vector<std::vector<Rune>> *input, size_t width) {
-  bool left = false;
+  bool left = true;
   for (auto &rv: *input) {
     while(rv.size() < width) {
       if (left) {
@@ -109,6 +109,7 @@ void padTo(std::vector<std::vector<Rune>
       }
       left = !left;
     }
+    left = true;
   }
 }
 
