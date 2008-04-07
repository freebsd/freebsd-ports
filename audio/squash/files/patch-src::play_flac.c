
$FreeBSD$

--- src/play_flac.c.orig
+++ src/play_flac.c
@@ -24,7 +24,7 @@
 #include "database.h" /* for insert_meta_data */
 #include "play_flac.h"
 
-void flac_error_callback(const FLAC__FileDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data) {
+void flac_error_callback(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data) {
     /* errors?  we don't need no stinking errors */
     return;
 }
@@ -36,47 +36,26 @@
  */
 void *flac_open( char *filename, sound_format_t *sound_format ) {
     flac_data_t *flac_data;
-    FLAC__FileDecoderState state;
+    FLAC__StreamDecoderInitStatus state;
 
     /* Allocate space for data */
     squash_malloc( flac_data, sizeof(flac_data_t) );
 
-    if( (flac_data->decoder = FLAC__file_decoder_new()) == NULL ) {
+    if( (flac_data->decoder = FLAC__stream_decoder_new()) == NULL ) {
         squash_free( flac_data );
         return (void *)NULL;
         // squash_error( "Unable to create flac decoder" );
     }
 
-    if( !FLAC__file_decoder_set_filename( flac_data->decoder, filename ) ) {
-        squash_free( flac_data );
-        return (void *)NULL;
-        // squash_error( "Unable to set filename in decoder" );
-    }
-
-    FLAC__file_decoder_set_metadata_callback( flac_data->decoder, flac_metadata_callback_decode_frame );
-
-    FLAC__file_decoder_set_write_callback( flac_data->decoder, flac_write_callback_decode_frame );
-
-    FLAC__file_decoder_set_error_callback( flac_data->decoder, flac_error_callback );
-
-    FLAC__file_decoder_set_client_data( flac_data->decoder, flac_data );
-
-    state = FLAC__file_decoder_init( flac_data->decoder );
+    state = FLAC__stream_decoder_init_file( flac_data->decoder, filename, flac_write_callback_decode_frame, flac_metadata_callback_decode_frame, flac_error_callback, flac_data );
     switch( state ) {
-        case FLAC__FILE_DECODER_OK:
+        case FLAC__STREAM_DECODER_INIT_STATUS_OK:
             /* no problem */
             break;
-        case FLAC__FILE_DECODER_END_OF_FILE:
-        case FLAC__FILE_DECODER_ERROR_OPENING_FILE:
-        case FLAC__FILE_DECODER_MEMORY_ALLOCATION_ERROR:
-        case FLAC__FILE_DECODER_SEEK_ERROR:
-        case FLAC__FILE_DECODER_SEEKABLE_STREAM_DECODER_ERROR:
-        case FLAC__FILE_DECODER_ALREADY_INITIALIZED:
-        case FLAC__FILE_DECODER_INVALID_CALLBACK:
-        case FLAC__FILE_DECODER_UNINITIALIZED:
+        default:
             squash_free( flac_data );
             return (void *)NULL;
-            // squash_error( "Unable to initialize decoder: %s", FLAC__FileDecoderStateString[ state ] );
+            // squash_error( "Unable to initialize decoder: %s", FLAC__StreamDecoderInitStatusString[ state ] );
             break;
     }
 
@@ -86,7 +65,7 @@
     flac_data->sample_rate = -1;
     flac_data->duration = -1;
 
-    FLAC__file_decoder_process_until_end_of_metadata( flac_data->decoder );
+    FLAC__stream_decoder_process_until_end_of_metadata( flac_data->decoder );
 
     sound_format->rate = flac_data->sample_rate;
     sound_format->channels = flac_data->channels;
@@ -97,12 +76,12 @@
     return (void *)flac_data;
 }
 
-FLAC__StreamDecoderWriteStatus flac_write_callback_load_meta( const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data ) {
+FLAC__StreamDecoderWriteStatus flac_write_callback_load_meta( const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data ) {
     /* do nothing ignore any decoded frames (when just loading meta data)*/
     return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 }
 
-void flac_metadata_callback_load_meta( const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data ) {
+void flac_metadata_callback_load_meta( const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data ) {
     FLAC__StreamMetadata_VorbisComment comment = metadata->data.vorbis_comment;
     int i;
     char *start, *end, *key, *value;
@@ -128,7 +107,7 @@
     }
 }
 
-FLAC__StreamDecoderWriteStatus flac_write_callback_decode_frame( const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data ) {
+FLAC__StreamDecoderWriteStatus flac_write_callback_decode_frame( const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data ) {
     flac_data_t *flac_data = (flac_data_t *)client_data;
     int i, j, k;
 
@@ -158,7 +137,7 @@
     return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 }
 
-void flac_metadata_callback_decode_frame( const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data ) {
+void flac_metadata_callback_decode_frame( const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data ) {
     flac_data_t *flac_data = (flac_data_t *)client_data;
 
     if( metadata->type != FLAC__METADATA_TYPE_STREAMINFO ) {
@@ -172,47 +151,29 @@
 }
 
 void flac_load_meta( void *data, char *filename ) {
-    FLAC__FileDecoder *decoder;
-    FLAC__FileDecoderState state;
+    FLAC__StreamDecoder *decoder;
+    FLAC__StreamDecoderInitStatus state;
 
-    if( (decoder = FLAC__file_decoder_new()) == NULL ) {
+    if( (decoder = FLAC__stream_decoder_new()) == NULL ) {
         squash_error( "Unable to create flac decoder" );
     }
 
-    if( !FLAC__file_decoder_set_filename( decoder, filename ) ) {
-        squash_error( "Unable to set filename in decoder" );
-    }
-
-    FLAC__file_decoder_set_metadata_callback( decoder, flac_metadata_callback_load_meta );
-    FLAC__file_decoder_set_metadata_respond_all( decoder );
-
-    FLAC__file_decoder_set_write_callback( decoder, flac_write_callback_load_meta );
-
-    FLAC__file_decoder_set_error_callback( decoder, flac_error_callback );
-
-    FLAC__file_decoder_set_client_data( decoder, data );
+    FLAC__stream_decoder_set_metadata_respond_all( decoder );
 
-    state = FLAC__file_decoder_init( decoder );
+    state = FLAC__stream_decoder_init_file( decoder, filename,  flac_write_callback_load_meta, flac_metadata_callback_load_meta, flac_error_callback, data );
     switch( state ) {
-        case FLAC__FILE_DECODER_OK:
+        case FLAC__STREAM_DECODER_INIT_STATUS_OK:
             /* no problem */
             break;
-        case FLAC__FILE_DECODER_END_OF_FILE:
-        case FLAC__FILE_DECODER_ERROR_OPENING_FILE:
-        case FLAC__FILE_DECODER_MEMORY_ALLOCATION_ERROR:
-        case FLAC__FILE_DECODER_SEEK_ERROR:
-        case FLAC__FILE_DECODER_SEEKABLE_STREAM_DECODER_ERROR:
-        case FLAC__FILE_DECODER_ALREADY_INITIALIZED:
-        case FLAC__FILE_DECODER_INVALID_CALLBACK:
-        case FLAC__FILE_DECODER_UNINITIALIZED:
-            squash_error( "Unable to initialize decoder: %s", FLAC__FileDecoderStateString[ state ] );
+        default:
+            squash_error( "Unable to initialize decoder: %s", FLAC__StreamDecoderInitStatusString[ state ] );
             break;
     }
 
-    FLAC__file_decoder_process_until_end_of_metadata( decoder );
+    FLAC__stream_decoder_process_until_end_of_metadata( decoder );
 
-    FLAC__file_decoder_finish( decoder );
-    FLAC__file_decoder_delete( decoder );
+    FLAC__stream_decoder_finish( decoder );
+    FLAC__stream_decoder_delete( decoder );
 
     return;
 }
@@ -223,29 +184,27 @@
 frame_data_t flac_decode_frame( void *data ) {
     flac_data_t *flac_data = (flac_data_t *)data;
     frame_data_t frame_data;
-    FLAC__FileDecoderState state;
+    FLAC__StreamDecoderState state;
 
-    FLAC__file_decoder_process_single( flac_data->decoder );
+    FLAC__stream_decoder_process_single( flac_data->decoder );
     frame_data.position = flac_data->position;
 
-    state = FLAC__file_decoder_get_state( flac_data->decoder );
+    state = FLAC__stream_decoder_get_state( flac_data->decoder );
     switch( state ) {
-        case FLAC__FILE_DECODER_OK:
+        case FLAC__STREAM_DECODER_READ_FRAME:
             frame_data.pcm_data = flac_data->buffer;
             frame_data.pcm_size = flac_data->buffer_size;
             break;
-        case FLAC__FILE_DECODER_END_OF_FILE:
+        case FLAC__STREAM_DECODER_END_OF_STREAM:
             frame_data.pcm_data = NULL;
             frame_data.pcm_size = 0;
             break;
-        case FLAC__FILE_DECODER_ERROR_OPENING_FILE:
-        case FLAC__FILE_DECODER_MEMORY_ALLOCATION_ERROR:
-        case FLAC__FILE_DECODER_SEEK_ERROR:
-        case FLAC__FILE_DECODER_SEEKABLE_STREAM_DECODER_ERROR:
-        case FLAC__FILE_DECODER_ALREADY_INITIALIZED:
-        case FLAC__FILE_DECODER_INVALID_CALLBACK:
-        case FLAC__FILE_DECODER_UNINITIALIZED:
-            squash_error("Error while decoding: %s", FLAC__FileDecoderStateString[ state ] );
+        case FLAC__STREAM_DECODER_OGG_ERROR:
+        case FLAC__STREAM_DECODER_SEEK_ERROR:
+        case FLAC__STREAM_DECODER_ABORTED:
+        case FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR:
+        case FLAC__STREAM_DECODER_UNINITIALIZED:
+            squash_error("Error while decoding: %s", FLAC__StreamDecoderStateString[ state ] );
             break;
     }
 
@@ -267,7 +226,7 @@
 void flac_seek( void *data, long seek_time, long duration ) {
     flac_data_t *flac_data = (flac_data_t *)data;
 
-    FLAC__file_decoder_seek_absolute( flac_data->decoder, seek_time * (flac_data->sample_rate / 1000) );
+    FLAC__stream_decoder_seek_absolute( flac_data->decoder, seek_time * (flac_data->sample_rate / 1000) );
     return;
 }
 
@@ -277,9 +236,9 @@
 void flac_close( void *data ) {
     flac_data_t *flac_data = (flac_data_t *)data;
 
-    FLAC__file_decoder_finish( flac_data->decoder );
+    FLAC__stream_decoder_finish( flac_data->decoder );
 
-    FLAC__file_decoder_delete( flac_data->decoder );
+    FLAC__stream_decoder_delete( flac_data->decoder );
 
     /* Free allocated storage */
     squash_free( flac_data->buffer );
