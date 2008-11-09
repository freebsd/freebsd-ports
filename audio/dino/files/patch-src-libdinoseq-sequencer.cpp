--- src/libdinoseq/sequencer.cpp.orig	2008-07-23 13:31:55.000000000 +0200
+++ src/libdinoseq/sequencer.cpp	2008-07-23 13:33:30.000000000 +0200
@@ -334,10 +334,10 @@
 	jack_port_t* port = m_output_ports[iter->get_id()];
 	if (port) {
 	  void* port_buf = jack_port_get_buffer(port, nframes);
-	  jack_midi_clear_buffer(port_buf, nframes);
+	  jack_midi_clear_buffer(port_buf);
 	  unsigned char all_notes_off[] = { 0xB0, 123, 0 };
 	  if (!m_sent_all_off)
-	    jack_midi_event_write(port_buf, 0, all_notes_off, 3, nframes);
+	    jack_midi_event_write(port_buf, 0, all_notes_off, 3);
 	}
 	m_sent_all_off = true;
       }
@@ -361,7 +361,7 @@
       jack_port_t* port = m_output_ports[iter->get_id()];
       if (port) {
 	void* port_buf = jack_port_get_buffer(port, nframes);
-	jack_midi_clear_buffer(port_buf, nframes);
+	jack_midi_clear_buffer(port_buf);
 	MIDIBuffer buffer(port_buf, start, pos.beats_per_minute,pos.frame_rate);
 	buffer.set_period_size(nframes);
 	buffer.set_cc_resolution(m_cc_resolution * pos.beats_per_minute / 60);
