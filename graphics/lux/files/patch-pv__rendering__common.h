--- pv_rendering_common.h.orig	2024-10-14 12:36:31 UTC
+++ pv_rendering_common.h
@@ -194,7 +194,7 @@ static const int max_degree = 7 ; // vspline_constants
 
 // typedef unsigned short fc_t ;
 
-typedef unsigned int fc_t ;
+typedef int fc_t ;
 
 #ifdef VECTORIZE
 
