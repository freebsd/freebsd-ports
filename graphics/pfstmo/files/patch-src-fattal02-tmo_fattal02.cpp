--- src/fattal02/tmo_fattal02.cpp.orig	2012-06-22 10:59:15.000000000 +0000
+++ src/fattal02/tmo_fattal02.cpp	2014-06-18 15:29:52.298957047 +0000
@@ -105,7 +105,6 @@
 {
   int width = I->getCols();
   int height = I->getRows();
-  int size = width*height;
   int x,y;
 
   pfstmo::Array2D* T = new pfstmo::Array2D(width,height);
