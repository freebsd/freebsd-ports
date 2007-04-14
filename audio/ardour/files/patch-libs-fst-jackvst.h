--- libs/fst/jackvst.h.orig	Wed Aug 30 22:49:25 2006
+++ libs/fst/jackvst.h	Sat Mar 24 16:58:18 2007
@@ -6,7 +6,9 @@
 #include <jack/jack.h>
 #include <jack/ringbuffer.h>
 #include <fst.h>
+#ifdef WITH_ALSA
 #include <alsa/asoundlib.h>
+#endif
 
 typedef struct _JackVST JackVST;
 
@@ -26,7 +28,9 @@
     /* For VST/i support */
 
     pthread_t          midi_thread;
+#ifdef WITH_ALSA
     snd_seq_t*         seq;
+#endif WITH_ALSA
     int                midiquit;
     jack_ringbuffer_t* event_queue;
     struct VstEvents*  events;
