--- src/items/Meditation.cc.orig	2014-12-19 21:24:33 UTC
+++ src/items/Meditation.cc
@@ -27,7 +27,7 @@ namespace enigma {
 
     Meditation::Meditation(int initState) {
         state = initState;
-        //whiteball = NULL;
+        whiteball = NULL;
     }
 
     std::string Meditation::getClass() const {
