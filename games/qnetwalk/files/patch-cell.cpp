--- cell.cpp.orig	2008-03-30 13:29:12.000000000 +0400
+++ cell.cpp	2013-08-07 21:24:52.637031376 +0400
@@ -19,7 +19,7 @@
 Cell::PixmapMap Cell::shadowpixmap;
 Cell::PixmapMap Cell::connectedpixmap;
 Cell::PixmapMap Cell::disconnectedpixmap;
-Cell::Cell * Cell::focusedCell = 0;
+Cell * Cell::focusedCell = 0;
 
 
 void Cell::setGameOver(bool b)
@@ -28,7 +28,7 @@
 }
 
 
-Cell::Cell * Cell::focused()
+Cell * Cell::focused()
 {
     return focusedCell;
 }
