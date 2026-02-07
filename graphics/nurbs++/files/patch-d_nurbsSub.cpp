--- nurbs/d_nurbsSub.cpp.orig	Mon May 13 13:11:57 2002
+++ nurbs/d_nurbsSub.cpp	Fri Dec  1 01:17:36 2006
@@ -14,8 +14,8 @@
   template class RenderMeshPoints<double> ;
 
   
-  double NurbSurface<double>::epsilon = 1e-6 ;
-  double SurfSample<double>::epsilon = 1e-6 ;
+  template <> double NurbSurface<double>::epsilon = 1e-6 ;
+  template <> double SurfSample<double>::epsilon = 1e-6 ;
 
   template void DrawSubdivision( NurbSurface<double> *, double tolerance );
   template void DrawEvaluation( NurbSurface<double> * );
