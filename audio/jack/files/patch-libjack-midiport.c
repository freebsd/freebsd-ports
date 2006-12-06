--- libjack/midiport.c.orig	Wed Dec  6 08:05:17 2006
+++ libjack/midiport.c	Wed Dec  6 08:05:56 2006
@@ -72,7 +72,7 @@
 		(jack_midi_port_info_private_t *) port_buffer;
 	
 	if (event_idx >= info->info.event_count)
-		return ENODATA;
+		return ENOMSG;
 	
 	port_event = (jack_midi_port_internal_event_t *) (info + 1);
 	port_event += event_idx;
