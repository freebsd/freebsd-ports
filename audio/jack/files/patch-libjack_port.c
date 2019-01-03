--- libjack/port.c.orig	2019-01-02 01:51:31 UTC
+++ libjack/port.c
@@ -630,13 +630,22 @@ jack_port_get_buffer (jack_port_t *port, jack_nframes_
 size_t
 jack_port_type_buffer_size (jack_port_type_info_t* port_type_info, jack_nframes_t nframes)
 {
+	size_t size;
+
 	if ( port_type_info->buffer_scale_factor < 0 ) {
 		return port_type_info->buffer_size;
 	}
 
-	return port_type_info->buffer_scale_factor
+	size = port_type_info->buffer_scale_factor
 	       * sizeof(jack_default_audio_sample_t)
 	       * nframes;
+
+#ifdef USE_DYNSIMD
+	/* Round up to the next multiple of 16 bytes, align buffers for SIMD. */
+	size = (size + 15) & (~ (size_t)0x0f);
+#endif  /* USE_DYNSIMD */
+
+	return size;
 }
 
 int
