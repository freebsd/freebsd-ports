--- src/rightangleline.cc.orig	Mon Dec 23 03:59:17 2002
+++ src/rightangleline.cc	Mon Dec 23 03:59:30 2002
@@ -283,7 +283,7 @@
   }
 }
 
-TCADRightAngleLine::TCADRightAngleLine(TCADSheet *Sheet,int x=0,int y=0) : TCADLine(Sheet,x,y)
+TCADRightAngleLine::TCADRightAngleLine(TCADSheet *Sheet,int x,int y) : TCADLine(Sheet,x,y)
 {
   int i;
   
