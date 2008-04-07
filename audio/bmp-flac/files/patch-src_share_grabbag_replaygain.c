--- src/share/grabbag/replaygain.c.orig	2004-02-12 09:00:39.000000000 +0100
+++ src/share/grabbag/replaygain.c	2008-04-06 21:03:18.000000000 +0200
@@ -19,8 +19,8 @@
 #include "share/grabbag.h"
 #include "share/replaygain_analysis.h"
 #include "FLAC/assert.h"
-#include "FLAC/file_decoder.h"
 #include "FLAC/metadata.h"
+#include "FLAC/stream_decoder.h"
 #include <locale.h>
 #include <math.h>
 #include <stdio.h>
@@ -266,7 +266,7 @@
 	FLAC__bool error;
 } DecoderInstance;
 
-static FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data)
+static FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data)
 {
 	DecoderInstance *instance = (DecoderInstance*)client_data;
 	const unsigned bits_per_sample = frame->header.bits_per_sample;
@@ -295,7 +295,7 @@
 		return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
 }
 
-static void metadata_callback_(const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
+static void metadata_callback_(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
 {
 	DecoderInstance *instance = (DecoderInstance*)client_data;
 
@@ -318,7 +318,7 @@
 	}
 }
 
-static void error_callback_(const FLAC__FileDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
+static void error_callback_(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
 {
 	DecoderInstance *instance = (DecoderInstance*)client_data;
 
@@ -330,7 +330,7 @@
 const char *grabbag__replaygain_analyze_file(const char *filename, float *title_gain, float *title_peak)
 {
 	DecoderInstance instance;
-	FLAC__FileDecoder *decoder = FLAC__file_decoder_new();
+	FLAC__StreamDecoder *decoder = FLAC__stream_decoder_new();
 
 	if(0 == decoder)
 		return "memory allocation error";
@@ -338,27 +338,22 @@
 	instance.error = false;
 
 	/* It does these three by default but lets be explicit: */
-	FLAC__file_decoder_set_md5_checking(decoder, false);
-	FLAC__file_decoder_set_metadata_ignore_all(decoder);
-	FLAC__file_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_STREAMINFO);
-
-	FLAC__file_decoder_set_filename(decoder, filename);
-	FLAC__file_decoder_set_write_callback(decoder, write_callback_);
-	FLAC__file_decoder_set_metadata_callback(decoder, metadata_callback_);
-	FLAC__file_decoder_set_error_callback(decoder, error_callback_);
-	FLAC__file_decoder_set_client_data(decoder, &instance);
+	FLAC__stream_decoder_set_md5_checking(decoder, false);
+	FLAC__stream_decoder_set_metadata_ignore_all(decoder);
+	FLAC__stream_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_STREAMINFO);
 
-	if(FLAC__file_decoder_init(decoder) != FLAC__FILE_DECODER_OK) {
-		FLAC__file_decoder_delete(decoder);
+
+	if(FLAC__stream_decoder_init_file(decoder, filename, write_callback_, metadata_callback_, error_callback_, &instance) != FLAC__STREAM_DECODER_INIT_STATUS_OK) {
+		FLAC__stream_decoder_delete(decoder);
 		return "initializing decoder";
 	}
 
-	if(!FLAC__file_decoder_process_until_end_of_file(decoder) || instance.error) {
-		FLAC__file_decoder_delete(decoder);
+	if(!FLAC__stream_decoder_process_until_end_of_stream(decoder) || instance.error) {
+		FLAC__stream_decoder_delete(decoder);
 		return "decoding file";
 	}
 
-	FLAC__file_decoder_delete(decoder);
+	FLAC__stream_decoder_delete(decoder);
 
 	grabbag__replaygain_get_title(title_gain, title_peak);
 
