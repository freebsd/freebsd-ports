$FreeBSD$

--- sndstretch.c.orig	Thu Sep 27 17:10:34 2001
+++ sndstretch.c	Sat Nov 10 12:54:19 2001
@@ -1053,9 +1053,11 @@
         
         speed_act = speed;
         pitch_act = pitch;
+#ifdef DEBUG
         if ( fade_shift != fade_shift_act ){
             fprintf(stderr,"changed fade_shift_act\n");
         }
+#endif
         fade_shift_act = fade_shift;
 
 //        if (ring_buff!=0) free(ring_buff);

