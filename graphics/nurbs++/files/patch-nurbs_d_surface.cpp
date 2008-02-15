--- nurbs/d_surface.cpp.orig	2008-02-13 22:34:54.000000000 +0100
+++ nurbs/d_surface.cpp	2008-02-13 22:35:05.000000000 +0100
@@ -19,21 +19,4 @@
     cerr << "NOT DEFINED FOR 2D SURFACES.\n" ; 
     return 0;
   }
-
-#ifdef NO_IMPLICIT_TEMPLATES
-  
-  template class InterPoint<double,2> ;
-  template class InterPoint<double,3> ;
-  
-  template class BasicList<InterPoint<double,2> > ; 
-  template class BasicList<InterPoint<double,3> > ; 
-  
-  template class ParaSurface<double,2> ;
-  template class ParaSurface<double,3> ;
-  
-  template void intersectSurfaces(const ParaSurface<double,2>&, const ParaSurface<double,2>&, BasicList<InterPoint<double,2> >&, int, double, double, double, double) ;
-  template void intersectSurfaces(const ParaSurface<double,3>&, const ParaSurface<double,3>&, BasicList<InterPoint<double,3> >&, int, double, double, double, double) ;
-  
-#endif 
-
 }
