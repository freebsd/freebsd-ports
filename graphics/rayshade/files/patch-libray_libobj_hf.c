--- libray/libobj/hf.c.orig	1992-02-10 03:04:18 UTC
+++ libray/libobj/hf.c
@@ -42,7 +42,7 @@ typedef struct {
 	Vector cp, pDX, pDY;
 } Trav2D;
 
-hfTri *CreateHfTriangle(), *GetQueuedTri();
+static hfTri *CreateHfTriangle(), *GetQueuedTri();
 
 unsigned long HFTests, HFHits;
 
