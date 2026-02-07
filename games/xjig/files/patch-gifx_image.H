--- gifx_image.H.orig	Mon Jul 15 12:59:11 1996
+++ gifx_image.H	Tue Apr  7 15:34:33 1998
@@ -29,6 +29,7 @@
 		void Reset8();
 		void Reset16();
 		void Reset32();
+		void Reset24();
 
 		Display	*dpy;
 		int		scr;
