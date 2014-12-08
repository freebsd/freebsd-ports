--- elektor.c.orig	2014-12-08 03:00:20.000000000 -0800
+++ elektor.c	2014-12-08 03:00:29.000000000 -0800
@@ -1020,7 +1020,7 @@
 
 //fprintf( stderr,"update-freq() cntrfreq=%f, hwfreq=%f\n",fg.passband_center,hwfreq);
   // This routine is called from the screen thread.
-  if ( abs(old_hwfreq-hwfreq) > 0.001 )
+  if ( fabs(old_hwfreq-hwfreq) > 0.001 )
   { Setup_Preselector();
     old_hwfreq = hwfreq;
   show_elektor_parms();
