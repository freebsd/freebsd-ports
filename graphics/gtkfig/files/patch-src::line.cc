--- src/line.cc.orig	Mon Dec 23 03:58:33 2002
+++ src/line.cc	Mon Dec 23 03:58:44 2002
@@ -14,7 +14,7 @@
 // he/she clicked on the line.
 #define SELECT_DISTANCE 4
 
-TCADLine::TCADLine(TCADSheet *Sheet,int x=0,int y=0) : TCADObject(Sheet)
+TCADLine::TCADLine(TCADSheet *Sheet,int x,int y) : TCADObject(Sheet)
 {
   First.x = x;
   First.y = y;
