--- libjack/midiport.c.orig	Sat Dec 16 13:50:17 2006
+++ libjack/midiport.c	Fri Jan 19 00:25:32 2007
@@ -77,7 +77,7 @@
 		(jack_midi_port_info_private_t *) port_buffer;
 	
 	if (event_idx >= info->event_count)
-		return ENODATA;
+		return ENOMSG;
 	
 	port_event = (jack_midi_port_internal_event_t *) (info + 1);
 	port_event += event_idx;
