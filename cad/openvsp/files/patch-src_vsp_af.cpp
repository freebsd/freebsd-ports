Workaround for libc++, which declares std::array even if not in C++11 mode (see
ports/207253 for a bigger discussion).
--- src/vsp/af.cpp.orig	2016-02-25 10:34:17 UTC
+++ src/vsp/af.cpp
@@ -1744,7 +1744,7 @@ vec3d Af::get_rounded_end_cap(int index)
 void Af::invert_airfoil()
 {
   int i;
-  array <double> z;
+  openvsp::array <double> z;
   z.init(num_pnts);
 
   //===== Switch Upper and Lower Z values =====
