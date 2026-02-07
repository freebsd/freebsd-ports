--- nurbs/f_surface.cpp.orig	2008-02-13 22:31:09.000000000 +0100
+++ nurbs/f_surface.cpp	2008-02-13 22:31:32.000000000 +0100
@@ -20,21 +20,4 @@
     return 0;
   }
   
-#ifdef NO_IMPLICIT_TEMPLATES
-  
-  template class InterPoint<float,2> ;
-  template class InterPoint<float,3> ;
-  
-  template class BasicList<InterPoint<float,2> > ; 
-  template class BasicList<InterPoint<float,3> > ; 
-  
-  template class ParaSurface<float,2> ;
-  template class ParaSurface<float,3> ;
-  
-  template void intersectSurfaces(const ParaSurface<float,2>&, const ParaSurface<float,2>&, BasicList<InterPoint<float,2> >&, int, float, float, float, float) ;
-  
-  template void intersectSurfaces(const ParaSurface<float,3>&, const ParaSurface<float,3>&, BasicList<InterPoint<float,3> >&, int, float, float, float, float) ;
-  
-#endif 
-
 }
