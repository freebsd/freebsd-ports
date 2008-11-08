--- src/jackdriver.c.orig	2008-07-23 13:54:34.000000000 +0200
+++ src/jackdriver.c	2008-07-23 13:54:49.000000000 +0200
@@ -81,7 +81,7 @@
      jack_midi_event_t jack_midi_event;
      jack_nframes_t event_index = 0;
 #ifdef HAVE_JACK_MIDI
-     jack_nframes_t event_count = jack_midi_get_event_count(midi_buf, frames);
+     jack_nframes_t event_count = jack_midi_get_event_count(midi_buf);
 #endif /* HAVE_JACK_MIDI */
 #ifdef HAVE_OLD_JACK_MIDI
      jack_nframes_t event_count = jack_midi_port_get_info(midi_buf, frames)->event_count;
@@ -123,7 +123,7 @@
      /* send the JACK MIDI events to the mixer */
      while (event_index < event_count) {
        
-         jack_midi_event_get(&jack_midi_event, midi_buf,event_index, frames);
+         jack_midi_event_get(&jack_midi_event, midi_buf,event_index);
 	  midi_data = jack_midi_event.buffer;
 	  
 	  /* TODO: handle 14-bit controllers and RPNs and NRPNs */
