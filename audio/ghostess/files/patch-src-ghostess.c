--- src/ghostess.c.orig	2006-11-28 06:39:41.000000000 +0100
+++ src/ghostess.c	2008-07-23 01:33:28.000000000 +0200
@@ -56,6 +56,7 @@
 #include <dirent.h>
 #include <pthread.h>
 #include <math.h>
+#include <errno.h>
 
 #include <gtk/gtk.h>
 
@@ -232,7 +233,7 @@
     void* midi_port_buf = jack_port_get_buffer(midi_input_port, nframes);
     jack_midi_event_t jack_midi_event;
     jack_nframes_t jack_midi_event_index = 0;
-    jack_nframes_t jack_midi_event_count = jack_midi_get_event_count(midi_port_buf, nframes);
+    jack_nframes_t jack_midi_event_count = jack_midi_get_event_count(midi_port_buf);
     static snd_seq_event_t jack_seq_event_holder[3];
     snd_seq_event_t *jack_seq_event = NULL, *osc_seq_event = NULL;
     int had_midi_overflow = 0;
@@ -258,7 +259,7 @@
 
             int count;
 
-            jack_midi_event_get(&jack_midi_event, midi_port_buf, jack_midi_event_index, nframes);
+            jack_midi_event_get(&jack_midi_event, midi_port_buf, jack_midi_event_index);
             jack_midi_event_index++;
 
             jack_seq_event = jack_seq_event_holder;
