--- src/audiointerface.h.orig	2012-09-20 22:44:28.775017000 +0900
+++ src/audiointerface.h	2012-10-05 06:05:30.000000000 +0900
@@ -228,6 +228,9 @@
 gboolean read_event_from_queue(backend_type_t backend, unsigned char *event_buffer, size_t *event_length,
                                double *event_time, double until_time);
 
+gboolean read_event_from_mixer_queue(backend_type_t backend, unsigned char *event_buffer, size_t *event_length,
+                               double *event_time, double until_time);
+
 /**
  * Called by a backend to notify the audio subsystem that the current playback
  * time changed. Usually this is called once per period during playback.
