--- src/simpleline.cc.orig	Mon Dec 23 04:01:18 2002
+++ src/simpleline.cc	Mon Dec 23 04:01:41 2002
@@ -8,7 +8,7 @@
 #include <math.h>
 #include "simpleline.h"
 
-TCADSimpleLine::TCADSimpleLine(TCADSheet *Sheet,int x=0,int y=0) : TCADLine(Sheet,x,y)
+TCADSimpleLine::TCADSimpleLine(TCADSheet *Sheet,int x,int y) : TCADLine(Sheet,x,y)
 {
   RecomputeEncapRect();
   RecomputeRefRect();
