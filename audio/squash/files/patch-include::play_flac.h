
$FreeBSD$

--- include/play_flac.h.orig
+++ include/play_flac.h
@@ -32,7 +32,7 @@
  * Structures
  */
 typedef struct flac_data_s {
-    FLAC__FileDecoder *decoder;
+    FLAC__StreamDecoder *decoder;
     char *buffer;
     int buffer_size;
     int channels;
@@ -45,11 +45,11 @@
  * Prototypes
  */
 void *flac_open( char *filename, sound_format_t *sound_format );
-void flac_error_callback( const FLAC__FileDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data );
-FLAC__StreamDecoderWriteStatus flac_write_callback_load_meta( const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data );
-void flac_metadata_callback_load_meta( const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data );
-FLAC__StreamDecoderWriteStatus flac_write_callback_decode_frame( const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data );
-void flac_metadata_callback_decode_frame( const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data );
+void flac_error_callback( const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data );
+FLAC__StreamDecoderWriteStatus flac_write_callback_load_meta( const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data );
+void flac_metadata_callback_load_meta( const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data );
+FLAC__StreamDecoderWriteStatus flac_write_callback_decode_frame( const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data );
+void flac_metadata_callback_decode_frame( const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data );
 void flac_load_meta( void *data, char *filename );
 frame_data_t flac_decode_frame( void *data );
 long flac_calc_duration( void *data );
