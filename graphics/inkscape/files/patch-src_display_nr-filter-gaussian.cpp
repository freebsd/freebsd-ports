--- src/display/nr-filter-gaussian.cpp.orig	2013-10-17 12:28:58.000000000 +0200
+++ src/display/nr-filter-gaussian.cpp	2013-10-17 12:58:55.000000000 +0200
@@ -708,7 +708,7 @@
         };
     } else if ( scr_len_x > 0 ) { // !use_IIR_x
         // Filter kernel for x direction
-        FIRValue kernel[scr_len_x+1];
+        std::vector<FIRValue> kernel(scr_len_x+1);
         _make_kernel(&kernel[0], deviation_x);
 
         // Filter (x)
@@ -770,7 +770,7 @@
         };
     } else if ( scr_len_y > 0 ) { // !use_IIR_y
         // Filter kernel for y direction
-        FIRValue kernel[scr_len_y+1];
+        std::vector<FIRValue> kernel(scr_len_y+1);
         _make_kernel(&kernel[0], deviation_y);
 
         // Filter (y)
