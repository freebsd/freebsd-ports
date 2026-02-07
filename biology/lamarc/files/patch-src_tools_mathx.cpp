--- src/tools/mathx.cpp.orig	2025-05-19 00:00:29 UTC
+++ src/tools/mathx.cpp
@@ -778,7 +778,7 @@ std::pair<DoubleVec1d, DoubleVec2d> EigenCalculator::E
     {
         eigvals[i] = a[i][i];
     }
-    return std::make_pair<DoubleVec1d, DoubleVec2d>(eigvals, eigvecs);
+    return std::make_pair(eigvals, eigvecs);
 } // Eigen
 
 //------------------------------------------------------------------------------------
