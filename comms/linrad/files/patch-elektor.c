--- elektor.c.orig	2014-11-04 10:25:00 UTC
+++ elektor.c
@@ -1018,7 +1018,7 @@ void update_elektor_rx_frequency()
 
 //fprintf( stderr,"update-freq() cntrfreq=%f, hwfreq=%f\n",fg.passband_center,hwfreq);
   // This routine is called from the screen thread.
-  if ( abs(old_hwfreq-hwfreq) > 0.001 )
+  if ( fabs(old_hwfreq-hwfreq) > 0.001 )
   { Setup_Preselector();
     old_hwfreq = hwfreq;
   show_elektor_parms();
