--- common/drivers/posix/sound_driver_jack.h.orig	Thu Apr 12 00:09:04 2007
+++ common/drivers/posix/sound_driver_jack.h	Thu Apr 12 00:09:21 2007
@@ -72,7 +72,7 @@
 
 	int jack_callback_nframes;
 
-	Sound_Driver::Status Sound_Driver_JACK::process();
+	Sound_Driver::Status process();
 
         static int process_jack_callback(jack_nframes_t nframes,void *arg);
         static int jack_set_mixfreq(jack_nframes_t nframes,void *arg);
