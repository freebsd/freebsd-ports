Fixes the redeclaration error. float vs const float.

--- src/mondrian.cc.orig	2021-07-12 13:10:37 UTC
+++ src/mondrian.cc
@@ -42,7 +42,7 @@ extern gotog _gotomax;
 extern int quit;
 extern beat2value octave_shift;
 extern float GOLDEN_RATIO;
-extern float PI_BY_180;
+extern const float PI_BY_180;
 extern int IPS; 
 extern std::map <string, float> INTERVALS;
 extern oscilloscope scope;
