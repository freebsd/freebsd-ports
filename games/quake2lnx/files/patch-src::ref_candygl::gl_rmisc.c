--- src/ref_candygl/gl_rmisc.c.orig	Thu Jun 12 18:05:46 2003
+++ src/ref_candygl/gl_rmisc.c	Thu Jun 12 18:08:56 2003
@@ -100,9 +100,6 @@
 	int		x,y;
 	byte	data[8][8][4];
 
-	byte	*pic, *palette;
-	int		width, height;
-	
 	partscale = (float)((int)gl_partscale->value)*0.01;
 	if (partscale>1)
 		partscale=1;
