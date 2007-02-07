--- libray/libsurf/fog.c.orig	Mon Feb 10 04:03:33 1992
+++ libray/libsurf/fog.c	Wed Feb  7 18:36:49 2007
@@ -28,7 +28,6 @@
 Color *color, *trans;
 {
 	Fog *fog;
-	static void ComputeFog();
 
 	fog = (Fog *)Malloc(sizeof(Fog));
 
