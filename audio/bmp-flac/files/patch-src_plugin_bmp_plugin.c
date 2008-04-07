--- src/plugin_bmp/plugin.c.orig	2008-04-06 19:21:13.000000000 +0200
+++ src/plugin_bmp/plugin.c	2008-04-06 19:45:38.000000000 +0200
@@ -80,12 +80,12 @@ static void FLAC_XMMS__cleanup();
 static void FLAC_XMMS__get_song_info(char *filename, char **title, int *length);
 
 static void *play_loop_(void *arg);
-static FLAC__bool safe_decoder_init_(const char *filename, FLAC__FileDecoder *decoder);
-static void safe_decoder_finish_(FLAC__FileDecoder *decoder);
-static void safe_decoder_delete_(FLAC__FileDecoder *decoder);
-static FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data);
-static void metadata_callback_(const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data);
-static void error_callback_(const FLAC__FileDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data);
+static FLAC__bool safe_decoder_init_(const char *filename, FLAC__StreamDecoder *decoder);
+static void safe_decoder_finish_(FLAC__StreamDecoder *decoder);
+static void safe_decoder_delete_(FLAC__StreamDecoder *decoder);
+static FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data);
+static void metadata_callback_(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data);
+static void error_callback_(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data);
 
 InputPlugin flac_ip =
 {
@@ -120,7 +120,7 @@ InputPlugin flac_ip =
 static FLAC__byte sample_buffer_[SAMPLE_BUFFER_SIZE];
 static unsigned sample_buffer_first_, sample_buffer_last_;
 
-static FLAC__FileDecoder *decoder_ = 0;
+static FLAC__StreamDecoder *decoder_ = 0;
 static file_info_struct file_info_;
 static pthread_t decode_thread_;
 static FLAC__bool audio_error_ = false;
@@ -186,7 +186,7 @@ void FLAC_XMMS__init()
 	if(!xmms_cfg_read_int(cfg, "flac", "output.resolution.replaygain.bps_out", &flac_cfg.output.resolution.replaygain.bps_out))
 		flac_cfg.output.resolution.replaygain.bps_out = 16;
 
-	decoder_ = FLAC__file_decoder_new();
+	decoder_ = FLAC__stream_decoder_new();
 
 	xmms_cfg_free(cfg);
 }
@@ -359,11 +359,11 @@ void *play_loop_(void *arg)
 				unsigned s;
 
 				s = sample_buffer_last_ - sample_buffer_first_;
-				if(FLAC__file_decoder_get_state(decoder_) == FLAC__FILE_DECODER_END_OF_FILE) {
+				if(FLAC__stream_decoder_get_state(decoder_) == FLAC__STREAM_DECODER_END_OF_STREAM) {
 					file_info_.eof = true;
 					break;
 				}
-				else if(!FLAC__file_decoder_process_single(decoder_)) {
+				else if(!FLAC__stream_decoder_process_single(decoder_)) {
 					/*@@@ this should probably be a dialog */
 					fprintf(stderr, "libxmms-flac: READ ERROR processing frame\n");
 					file_info_.eof = true;
@@ -371,7 +371,7 @@ void *play_loop_(void *arg)
 				}
 				blocksize = sample_buffer_last_ - sample_buffer_first_ - s;
 				decode_position_frame_last = decode_position_frame;
-				if(!FLAC__file_decoder_get_decode_position(decoder_, &decode_position_frame))
+				if(!FLAC__stream_decoder_get_decode_position(decoder_, &decode_position_frame))
 					decode_position_frame = 0;
 			}
 			if(sample_buffer_last_ - sample_buffer_first_ > 0) {
@@ -413,10 +413,10 @@ void *play_loop_(void *arg)
 		if(file_info_.seek_to_in_sec != -1) {
 			const double distance = (double)file_info_.seek_to_in_sec * 1000.0 / (double)file_info_.length_in_msec;
 			unsigned target_sample = (unsigned)(distance * (double)file_info_.total_samples);
-			if(FLAC__file_decoder_seek_absolute(decoder_, (FLAC__uint64)target_sample)) {
+			if(FLAC__stream_decoder_seek_absolute(decoder_, (FLAC__uint64)target_sample)) {
 				flac_ip.output->flush(file_info_.seek_to_in_sec * 1000);
 				bh_index_last_w = bh_index_last_o = flac_ip.output->output_time() / BITRATE_HIST_SEGMENT_MSEC % BITRATE_HIST_SIZE;
-				if(!FLAC__file_decoder_get_decode_position(decoder_, &decode_position_frame))
+				if(!FLAC__stream_decoder_get_decode_position(decoder_, &decode_position_frame))
 					decode_position_frame = 0;
 				file_info_.seek_to_in_sec = -1;
 				file_info_.eof = false;
@@ -445,46 +445,41 @@ void *play_loop_(void *arg)
 	return 0; /* to silence the compiler warning about not returning a value */
 }
 
-FLAC__bool safe_decoder_init_(const char *filename, FLAC__FileDecoder *decoder)
+FLAC__bool safe_decoder_init_(const char *filename, FLAC__StreamDecoder *decoder)
 {
 	if(decoder == 0)
 		return false;
 
 	safe_decoder_finish_(decoder);
 
-	FLAC__file_decoder_set_md5_checking(decoder, false);
-	FLAC__file_decoder_set_filename(decoder, filename);
-	FLAC__file_decoder_set_metadata_ignore_all(decoder);
-	FLAC__file_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_STREAMINFO);
-	FLAC__file_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_VORBIS_COMMENT);
-	FLAC__file_decoder_set_write_callback(decoder, write_callback_);
-	FLAC__file_decoder_set_metadata_callback(decoder, metadata_callback_);
-	FLAC__file_decoder_set_error_callback(decoder, error_callback_);
-	FLAC__file_decoder_set_client_data(decoder, &file_info_);
-	if(FLAC__file_decoder_init(decoder) != FLAC__FILE_DECODER_OK)
+	FLAC__stream_decoder_set_md5_checking(decoder, false);
+	FLAC__stream_decoder_set_metadata_ignore_all(decoder);
+	FLAC__stream_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_STREAMINFO);
+	FLAC__stream_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_VORBIS_COMMENT);
+	if(FLAC__stream_decoder_init_file(decoder, filename, write_callback_, metadata_callback_, error_callback_, /*client_data=*/&file_info_) != FLAC__STREAM_DECODER_INIT_STATUS_OK)
 		return false;
 
-	if(!FLAC__file_decoder_process_until_end_of_metadata(decoder))
+	if(!FLAC__stream_decoder_process_until_end_of_metadata(decoder))
 		return false;
 
 	return true;
 }
 
-void safe_decoder_finish_(FLAC__FileDecoder *decoder)
+void safe_decoder_finish_(FLAC__StreamDecoder *decoder)
 {
-	if(decoder && FLAC__file_decoder_get_state(decoder) != FLAC__FILE_DECODER_UNINITIALIZED)
-		FLAC__file_decoder_finish(decoder);
+	if(decoder && FLAC__stream_decoder_get_state(decoder) != FLAC__STREAM_DECODER_UNINITIALIZED)
+		FLAC__stream_decoder_finish(decoder);
 }
 
-void safe_decoder_delete_(FLAC__FileDecoder *decoder)
+void safe_decoder_delete_(FLAC__StreamDecoder *decoder)
 {
 	if(decoder) {
 		safe_decoder_finish_(decoder);
-		FLAC__file_decoder_delete(decoder);
+		FLAC__stream_decoder_delete(decoder);
 	}
 }
 
-FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__FileDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data)
+FLAC__StreamDecoderWriteStatus write_callback_(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data)
 {
 	file_info_struct *file_info = (file_info_struct *)client_data;
 	const unsigned channels = file_info->channels, wide_samples = frame->header.blocksize;
@@ -544,7 +539,7 @@ FLAC__StreamDecoderWriteStatus write_cal
 	return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 }
 
-void metadata_callback_(const FLAC__FileDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
+void metadata_callback_(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
 {
 	file_info_struct *file_info = (file_info_struct *)client_data;
 	(void)decoder;
@@ -565,7 +560,7 @@ void metadata_callback_(const FLAC__File
 	}
 }
 
-void error_callback_(const FLAC__FileDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
+void error_callback_(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
 {
 	file_info_struct *file_info = (file_info_struct *)client_data;
 	(void)decoder;
