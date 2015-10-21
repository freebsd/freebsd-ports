--- nurbs/d_nurbs.cpp.orig	2008-02-13 22:33:03.000000000 +0100
+++ nurbs/d_nurbs.cpp	2008-02-13 22:33:32.000000000 +0100
@@ -10,7 +10,7 @@
   return firstDn(u) ;
 }
 
-void NurbsCurve<double,2>::makeCircle(const Point_nD<double,2>& O, double r, double as, double ae){
+template<> void NurbsCurve<double,2>::makeCircle(const Point_nD<double,2>& O, double r, double as, double ae){
   makeCircle(O,Point_nD<double,2>(1,0),Point_nD<double,2>(0,1),r,as,ae) ;
 }
 
