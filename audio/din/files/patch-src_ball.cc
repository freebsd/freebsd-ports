Fixes the redeclaration error. float vs const float.

--- src/ball.cc.orig	2021-07-12 10:55:38 UTC
+++ src/ball.cc
@@ -14,7 +14,7 @@
 using namespace std;
 
 extern mondrian mondrian0;
-extern float PI_BY_180;
+extern const float PI_BY_180;
 extern float TWO_PI;
 extern int TRAILSIZE;
 
