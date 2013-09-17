--- src/Utils.cpp.orig	2013-04-01 18:21:13.000000000 +0400
+++ src/Utils.cpp	2013-09-17 05:57:39.713315065 +0400
@@ -25,14 +25,14 @@
 using namespace std;
 
 
-int round(float f) {
+int myround(float f) {
 	return (int)(f + 0.5);
 }
 
 Point round(FPoint fp) {
 	Point result;
-	result.x = round(fp.x);
-	result.y = round(fp.y);
+	result.x = myround(fp.x);
+	result.y = myround(fp.y);
 	return result;
 }
 
