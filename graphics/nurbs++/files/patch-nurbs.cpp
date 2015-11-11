--- nurbs/nurbs.cpp.orig	Fri May 24 10:25:49 2002
+++ nurbs/nurbs.cpp	Fri Dec  1 00:22:20 2006
@@ -28,7 +28,7 @@
 #include <nurbsS.h>
 #include "integrate.h"
 
-#include <malloc.h>
+#include <stdlib.h>
 
 /*!
  */
@@ -391,9 +391,9 @@
   T du,dv ;
   // compute a coarse distance for the curve
   Point_nD<T,N> a,b,c ;
-  a = pointAt(0.0) ;
-  b = pointAt(0.5) ;
-  c = pointAt(1.0) ;
+  a = this->pointAt(0.0) ;
+  b = this->pointAt(0.5) ;
+  c = this->pointAt(1.0) ;
 
   T distance = norm(b-a) + norm(c-b) ;
 
@@ -2396,7 +2396,7 @@
       r = c ;
       return ;
     }
-    c = pointAt(u) ;
+    c = this->pointAt(u) ;
     deriveAt(u,2,Cd) ;
     cd = Cd[1] ;
     cdd = Cd[2] ;
@@ -5202,7 +5202,7 @@
 */
 template <class T, int N>
 BasicList<Point_nD<T,N> > NurbsCurve<T,N>::tesselate(T tolerance,BasicList<T> *uk) const {
-  BasicList<Point_nD<T,N> > list,list2 ;
+  BasicList<Point_nD<T,N> > list, list2 ;
 
   NurbsCurveArray<T,N> ca ;
   decompose(ca) ;
@@ -5240,7 +5240,7 @@
 
     for(i=0;i<n;++i){
       u = (U[U.n()-deg_-1]-U[deg_])*T(i)/T(n-1) + U[deg_] ;
-      list.add(pointAt(u)) ;
+      list.add(this->pointAt(u)) ;
       if(uk)
 	uk->add(u) ;
     }
@@ -5249,7 +5249,7 @@
   }
   else{
     for(int i=0;i<ca.n();++i){
-      list2 = ca[i].tesselate(tolerance,uk) ;
+      list2 = ca[i].tesselate(tolerance,uk).by_ref() ;
 
       // remove the last point from the list to elliminate
       list.erase((BasicNode<Point_nD<T,N> >*)list.last()) ;
