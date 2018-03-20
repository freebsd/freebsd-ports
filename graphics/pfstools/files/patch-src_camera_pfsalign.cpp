--- src/camera/pfsalign.cpp.orig	2018-03-01 12:03:22 UTC
+++ src/camera/pfsalign.cpp
@@ -643,7 +643,7 @@ void alignFrames(int argc, char *argv[])
 
         homoMC.push_back( trans );
 
-        double data[4][3] = { { 0, 0, 1 }, { frames[kk].size.width, 0, 1 }, { frames[kk].size.width, frames[kk].size.height, 1 }, { 0, frames[kk].size.height, 1 } };
+        double data[4][3] = { { 0.0, 0.0, 1.0 }, { static_cast<double>(frames[kk].size.width), 0.0, 1.0 }, { static_cast<double>(frames[kk].size.width), static_cast<double>(frames[kk].size.height), 1.0 }, { 0.0, static_cast<double>(frames[kk].size.height), 1.0 } };
         Mat corners( 4, 3, CV_64F, data );
 
         Mat corners_trans = trans * corners.t();
