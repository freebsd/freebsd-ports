
$FreeBSD$

--- pieces.cc.orig	Mon Jun 17 05:24:31 2002
+++ pieces.cc	Sat Sep 28 23:00:58 2002
@@ -1198,7 +1198,7 @@
   global.destroy("VectorPieces");
 }
 
-void VectorPieces::drawSquares(GdkPixmap *dest,GdkGC *gc,int sqside, int dx=0, int dy=0) {
+void VectorPieces::drawSquares(GdkPixmap *dest,GdkGC *gc,int sqside, int dx, int dy) {
   int i,j;
   for(i=0;i<8;i++)
     for(j=0;j<8;j++) {      
