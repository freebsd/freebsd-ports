--- elektor.c.orig	2014-11-04 10:25:00 UTC
+++ elektor.c
@@ -1013,12 +1013,12 @@ void elektor_rx_amp_control(void)
   }
 }
 
-void update_elektor_rx_frequency()
+void update_elektor_rx_frequency(void)
 { static double old_hwfreq=0.0;
 
 //fprintf( stderr,"update-freq() cntrfreq=%f, hwfreq=%f\n",fg.passband_center,hwfreq);
   // This routine is called from the screen thread.
-  if ( abs(old_hwfreq-hwfreq) > 0.001 )
+  if ( fabs(old_hwfreq-hwfreq) > 0.001 )
   { Setup_Preselector();
     old_hwfreq = hwfreq;
   show_elektor_parms();
@@ -1441,7 +1441,7 @@ int calc_Mux(double freq)
   return 2;             // Use the SW setting for all others.
 }
 
-void Setup_Preselector()
+void Setup_Preselector(void)
 {
 //fprintf( stderr,"Setup_Preselector: ActMux=%d\n",ActiveMux);
   if ( ActiveMux >= 3  &&  ActiveMux <= 6 )
