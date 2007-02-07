--- libray/libsurf/fogdeck.c.orig	Mon Feb 10 04:03:45 1992
+++ libray/libsurf/fogdeck.c	Wed Feb  7 18:37:51 2007
@@ -31,7 +31,6 @@
 Color *color, *trans;
 {
 	Fogdeck *fogdeck;
-	static void ComputeFogdeck();
 
 	fogdeck = (Fogdeck *)Malloc(sizeof(Fogdeck));
 
