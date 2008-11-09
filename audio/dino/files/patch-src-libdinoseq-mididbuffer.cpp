--- src/libdinoseq/midibuffer.cpp.orig	2008-07-23 13:26:56.000000000 +0200
+++ src/libdinoseq/midibuffer.cpp	2008-07-23 13:27:11.000000000 +0200
@@ -55,7 +55,7 @@
     // XXX optimise this
     jack_nframes_t timestamp = jack_nframes_t((beat - m_start_beat) * 
 					      60 / (m_bpm * m_samplerate));
-    return jack_midi_event_reserve(m_buffer, timestamp, data_size, m_nframes);
+    return jack_midi_event_reserve(m_buffer, timestamp, data_size);
   }
     
   
@@ -65,7 +65,7 @@
     jack_nframes_t timestamp = jack_nframes_t((beat - m_start_beat) * 
 					      60 / (m_bpm * m_samplerate));
     return jack_midi_event_write(m_buffer, timestamp, (jack_midi_data_t*)data, 
-				 data_size, m_nframes);
+				 data_size);
   }
 
 
