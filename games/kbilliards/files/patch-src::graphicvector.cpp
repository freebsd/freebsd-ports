--- src/graphicvector.cpp.orig	Wed Jan 19 08:09:41 2005
+++ src/graphicvector.cpp	Thu Jan 20 19:41:18 2005
@@ -64,5 +64,5 @@
  */
 void GraphicVector::advance(int)
 {
-     setPoints((int)round(startx),(int)round(starty),(int)round(endx),(int)round(endy));
+     setPoints((int)rint(startx),(int)rint(starty),(int)rint(endx),(int)rint(endy));
 }
