--- libray/libsurf/fogdeck.c.orig	1992-02-10 03:03:45 UTC
+++ libray/libsurf/fogdeck.c
@@ -31,7 +31,6 @@ int octaves;
 Color *color, *trans;
 {
 	Fogdeck *fogdeck;
-	static void ComputeFogdeck();
 
 	fogdeck = (Fogdeck *)Malloc(sizeof(Fogdeck));
 
