--- nurbs/nurbsS.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/nurbsS.cpp	Fri Dec  1 00:32:26 2006
@@ -30,7 +30,7 @@
 #include "integrate.h"
 
 #ifdef USING_VCC
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /*!
@@ -3762,12 +3762,12 @@
   // we use and angle of 36 to view the object
   // and position the rest according to this.
   Point_nD<T,N> minP, maxP ;
-  minP.x() = extremum(1,coordX) ;
-  minP.y() = extremum(1,coordY) ;
-  minP.z() = extremum(1,coordZ) ;
-  maxP.x() = extremum(0,coordX) ;
-  maxP.y() = extremum(0,coordY) ;
-  maxP.z() = extremum(0,coordZ) ;
+  minP.x() = this->extremum(1,coordX) ;
+  minP.y() = this->extremum(1,coordY) ;
+  minP.z() = this->extremum(1,coordZ) ;
+  maxP.x() = this->extremum(0,coordX) ;
+  maxP.y() = this->extremum(0,coordY) ;
+  maxP.z() = this->extremum(0,coordZ) ;
 
   Point_nD<T,N> lookAt  ;
   lookAt.x() = (minP.x()+maxP.x())/2.0 ;
@@ -3860,12 +3860,12 @@
   // we use and angle of 36 to view the object
   // and position the rest according to this.
   Point_nD<T,N> minP, maxP ;
-  minP.x() = extremum(1,coordX) ;
-  minP.y() = extremum(1,coordY) ;
-  minP.z() = extremum(1,coordZ) ;
-  maxP.x() = extremum(0,coordX) ;
-  maxP.y() = extremum(0,coordY) ;
-  maxP.z() = extremum(0,coordZ) ;
+  minP.x() = this->extremum(1,coordX) ;
+  minP.y() = this->extremum(1,coordY) ;
+  minP.z() = this->extremum(1,coordZ) ;
+  maxP.x() = this->extremum(0,coordX) ;
+  maxP.y() = this->extremum(0,coordY) ;
+  maxP.z() = this->extremum(0,coordZ) ;
 
   Point_nD<T,N> lookAt  ;
   lookAt.x() = (minP.x()+maxP.x())/2.0 ;
@@ -4045,12 +4045,12 @@
   }
 
   Point_nD<T,N> minP, maxP ;
-  minP.x() = extremum(1,coordX) ;
-  minP.y() = extremum(1,coordY) ;
-  minP.z() = extremum(1,coordZ) ;
-  maxP.x() = extremum(0,coordX) ;
-  maxP.y() = extremum(0,coordY) ;
-  maxP.z() = extremum(0,coordZ) ;
+  minP.x() = this->extremum(1,coordX) ;
+  minP.y() = this->extremum(1,coordY) ;
+  minP.z() = this->extremum(1,coordZ) ;
+  maxP.x() = this->extremum(0,coordX) ;
+  maxP.y() = this->extremum(0,coordY) ;
+  maxP.z() = this->extremum(0,coordZ) ;
 
   Point_nD<T,N> lookAt  ;
   lookAt.x() = (minP.x()+maxP.x())/2.0 ;
@@ -4715,7 +4715,7 @@
   T u,v;
   for (u = fBu; u<fEu+fDu/2; u+=fDu)
     for (v = fBv; v<fEv+fDv/2; v+=fDv){
-      Sp = pointAt(u,v);
+      Sp = this->pointAt(u,v);
       Np = normal(u,v);
       Np = (norm(Np)!=0)?Np.unitLength():Point_nD<T,N>(0.0);
       fout << "\t" << Sp << "\t " << Np << endl;
@@ -4829,7 +4829,7 @@
     for (u = 0; u<1-fDu/2; u+=fDu){
       // The change in sign and the swap of y and z coordinates is
       // for conversion to MINC format.
-      Sp = -(T)1.0 * pointAt(u,v) ;
+      Sp = -(T)1.0 * this->pointAt(u,v) ;
       fout << Sp.x() << ' ' << Sp.z() << ' ' << Sp.y() << endl;
     }
 
