--- nurbs/f_nurbsSub.cpp.orig	Mon May 13 13:11:57 2002
+++ nurbs/f_nurbsSub.cpp	Fri Dec  1 01:15:08 2006
@@ -14,8 +14,8 @@
   template class RenderMeshPoints<float> ;
 
   
-  float NurbSurface<float>::epsilon = 1e-6 ;
-  float SurfSample<float>::epsilon = 1e-6 ;
+  template <> float NurbSurface<float>::epsilon = 1e-6 ;
+  template <> float SurfSample<float>::epsilon = 1e-6 ;
 
   template void DrawSubdivision( NurbSurface<float> *, float tolerance );
   template void DrawEvaluation( NurbSurface<float> * );
