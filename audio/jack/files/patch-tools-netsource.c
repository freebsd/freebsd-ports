--- tools/netsource.c.orig	2009-11-13 09:59:11.301019727 +0100
+++ tools/netsource.c	2009-11-13 09:59:42.991223929 +0100
@@ -124,8 +124,8 @@ alloc_ports (int n_capture_audio, int n_
 	if( bitdepth == 1000 ) {
 #if HAVE_CELT
 	    // XXX: memory leak
-	    CELTMode *celt_mode = celt_mode_create( jack_get_sample_rate( client ), 1, jack_get_buffer_size(client), NULL );
-	    capture_srcs = jack_slist_append(capture_srcs, celt_decoder_create( celt_mode ) );
+	    CELTMode *celt_mode = celt_mode_create( jack_get_sample_rate( client ), jack_get_buffer_size(client), NULL );
+	    capture_srcs = jack_slist_append(capture_srcs, celt_decoder_create( celt_mode, 1, NULL ) );
 #endif
 	} else {
 #if HAVE_SAMPLERATE
@@ -163,8 +163,8 @@ alloc_ports (int n_capture_audio, int n_
 	if( bitdepth == 1000 ) {
 #if HAVE_CELT
 	    // XXX: memory leak
-	    CELTMode *celt_mode = celt_mode_create( jack_get_sample_rate (client), 1, jack_get_buffer_size(client), NULL );
-	    playback_srcs = jack_slist_append(playback_srcs, celt_encoder_create( celt_mode ) );
+	    CELTMode *celt_mode = celt_mode_create( jack_get_sample_rate (client), jack_get_buffer_size(client), NULL );
+	    playback_srcs = jack_slist_append(playback_srcs, celt_encoder_create( celt_mode, 1, NULL ) );
 #endif
 	} else {
 #if HAVE_SAMPLERATE
