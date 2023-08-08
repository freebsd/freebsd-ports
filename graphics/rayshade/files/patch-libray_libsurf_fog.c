--- libray/libsurf/fog.c.orig	1992-02-10 03:03:33 UTC
+++ libray/libsurf/fog.c
@@ -28,7 +28,6 @@ FogCreate(color, trans)
 Color *color, *trans;
 {
 	Fog *fog;
-	static void ComputeFog();
 
 	fog = (Fog *)Malloc(sizeof(Fog));
 
