--- libray/libobj/hf.c.orig	Mon Feb 10 04:04:18 1992
+++ libray/libobj/hf.c	Wed Feb  7 18:27:10 2007
@@ -42,7 +42,7 @@
 	Vector cp, pDX, pDY;
 } Trav2D;
 
-hfTri *CreateHfTriangle(), *GetQueuedTri();
+static hfTri *CreateHfTriangle(), *GetQueuedTri();
 
 unsigned long HFTests, HFHits;
 
