--- gd_png.c.orig	Thu Apr 25 14:15:42 2002
+++ gd_png.c	Thu Apr 25 12:43:55 2002
@@ -225,7 +225,7 @@
 	      im->alpha[i] = gdAlphaMax - (trans[i] >> 1);
 	      if ((trans[i] == 0) && (firstZero))
 		{
-		  im->transparent = i;
+					  transparent = i;
 		  firstZero = 0;
 		}
 	    }
