--- ppm.h.orig	Wed Dec 17 11:56:17 2003
+++ ppm.h	Wed Dec 17 11:57:01 2003
@@ -189,7 +189,7 @@
 		}
 
 		if (mcv != CHANNEL_MAX)
-			ival = (int) round(((double) ival / (double) (mcv)) * (CHANNEL_MAX));
+			ival = (int) ceil(((double) ival / (double) (mcv)) * (CHANNEL_MAX) + 0.5);
 
 		im->set_pixel_component(i, j, k, ival);
 	}
