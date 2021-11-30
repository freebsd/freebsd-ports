--- fon/Praat_tests.cpp.orig	2021-11-30 13:24:45 UTC
+++ fon/Praat_tests.cpp
@@ -742,7 +742,7 @@ class Vec { (public)
 };
 
 static Vec copy (Vec x) {
-	return x;
+	return Vec(x);
 }
 
 /*static void tryVec () {
