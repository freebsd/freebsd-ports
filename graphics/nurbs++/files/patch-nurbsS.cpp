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
