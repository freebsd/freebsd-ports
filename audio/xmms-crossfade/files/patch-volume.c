--- volume.c.orig	Tue Sep 14 18:38:00 2004
+++ volume.c	Mon Nov 22 09:46:55 2004
@@ -81,11 +81,12 @@
 
 gfloat volume_compute_factor(gint percent, gint dB_range)
 {
+  gfloat dB;
   if(percent>=100)
     return 1;
   if(percent<=0)
     return 0;
-  gfloat dB  = (percent-100)/100.0*dB_range; 
+  dB  = (percent-100)/100.0*dB_range; 
   return pow(10, dB/20);
 }
 
