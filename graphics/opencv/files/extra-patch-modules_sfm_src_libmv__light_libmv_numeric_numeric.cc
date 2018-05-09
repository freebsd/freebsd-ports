--- modules/sfm/src/libmv_light/libmv/numeric/numeric.cc.orig	2018-04-27 13:11:58.957812000 +0000
+++ modules/sfm/src/libmv_light/libmv/numeric/numeric.cc	2018-04-27 15:52:13.702374000 +0000
@@ -24,8 +24,8 @@
 namespace libmv {
 
 Mat3 RotationAroundX(double angle) {
-  double c, s;
-  sincos(angle, &s, &c);
+  double c = cos(angle);
+  double s = sin(angle);
   Mat3 R;
   R << 1,  0,  0,
        0,  c, -s,
@@ -34,8 +34,8 @@ Mat3 RotationAroundX(double angle) {
 }
 
 Mat3 RotationAroundY(double angle) {
-  double c, s;
-  sincos(angle, &s, &c);
+  double c = cos(angle);
+  double s = sin(angle);
   Mat3 R;
   R <<  c, 0, s,
         0, 1, 0,
@@ -44,8 +44,8 @@ Mat3 RotationAroundY(double angle) {
 }
 
 Mat3 RotationAroundZ(double angle) {
-  double c, s;
-  sincos(angle, &s, &c);
+  double c = cos(angle);
+  double s = sin(angle);
   Mat3 R;
   R << c, -s,  0,
        s,  c,  0,
