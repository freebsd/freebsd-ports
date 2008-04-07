--- src/flac.c.orig	2006-08-31 11:22:19.000000000 +0200
+++ src/flac.c	2008-03-28 17:07:29.000000000 +0100
@@ -46,6 +46,13 @@
 #include	"sfendian.h"
 #include	"float_cast.h"
 
+/* FLAC 1.1.3 has FLAC_API_VERSION_CURRENT == 8 */
+#if !defined(FLAC_API_VERSION_CURRENT) || FLAC_API_VERSION_CURRENT < 8
+#define LEGACY_FLAC
+#else
+#undef LEGACY_FLAC
+#endif
+
 /*------------------------------------------------------------------------------
 ** Private static functions.
 */
@@ -60,8 +67,14 @@
 } PFLAC_PCM ;
 
 typedef struct
-{	FLAC__SeekableStreamDecoder *fsd ;
+{
+#ifdef LEGACY_FLAC
+	FLAC__SeekableStreamDecoder *fsd ;
 	FLAC__SeekableStreamEncoder *fse ;
+#else
+	FLAC__StreamDecoder *fsd ;
+	FLAC__StreamEncoder *fse ;
+#endif
 	PFLAC_PCM pcmtype ;
 	void* ptr ;
 	unsigned pos, len, remain ;
@@ -108,6 +121,7 @@
 static int flac_command (SF_PRIVATE *psf, int command, void *data, int datasize) ;
 
 /* Decoder Callbacks */
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamDecoderReadStatus sf_flac_read_callback (const FLAC__SeekableStreamDecoder *decoder, FLAC__byte buffer [], unsigned *bytes, void *client_data) ;
 static FLAC__SeekableStreamDecoderSeekStatus sf_flac_seek_callback (const FLAC__SeekableStreamDecoder *decoder, FLAC__uint64 absolute_byte_offset, void *client_data) ;
 static FLAC__SeekableStreamDecoderTellStatus sf_flac_tell_callback (const FLAC__SeekableStreamDecoder *decoder, FLAC__uint64 *absolute_byte_offset, void *client_data) ;
@@ -116,13 +130,29 @@
 static FLAC__StreamDecoderWriteStatus sf_flac_write_callback (const FLAC__SeekableStreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer [], void *client_data) ;
 static void sf_flac_meta_callback (const FLAC__SeekableStreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data) ;
 static void sf_flac_error_callback (const FLAC__SeekableStreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data) ;
+#else
+static FLAC__StreamDecoderReadStatus sf_flac_read_callback (const FLAC__StreamDecoder *decoder, FLAC__byte buffer [], size_t *bytes, void *client_data) ;
+static FLAC__StreamDecoderSeekStatus sf_flac_seek_callback (const FLAC__StreamDecoder *decoder, FLAC__uint64 absolute_byte_offset, void *client_data) ;
+static FLAC__StreamDecoderTellStatus sf_flac_tell_callback (const FLAC__StreamDecoder *decoder, FLAC__uint64 *absolute_byte_offset, void *client_data) ;
+static FLAC__StreamDecoderLengthStatus sf_flac_length_callback (const FLAC__StreamDecoder *decoder, FLAC__uint64 *stream_length, void *client_data) ;
+static FLAC__bool sf_flac_eof_callback (const FLAC__StreamDecoder *decoder, void *client_data) ;
+static FLAC__StreamDecoderWriteStatus sf_flac_write_callback (const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer [], void *client_data) ;
+static void sf_flac_meta_callback (const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data) ;
+static void sf_flac_error_callback (const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data) ;
+#endif
 
 /* Encoder Callbacks */
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamEncoderSeekStatus sf_flac_enc_seek_callback (const FLAC__SeekableStreamEncoder *encoder, FLAC__uint64 absolute_byte_offset, void *client_data) ;
 #ifdef HAVE_FLAC_1_1_1
 static FLAC__SeekableStreamEncoderTellStatus sf_flac_enc_tell_callback (const FLAC__SeekableStreamEncoder *encoder, FLAC__uint64 *absolute_byte_offset, void *client_data) ;
 #endif
 static FLAC__StreamEncoderWriteStatus sf_flac_enc_write_callback (const FLAC__SeekableStreamEncoder *encoder, const FLAC__byte buffer [], unsigned bytes, unsigned samples, unsigned current_frame, void *client_data) ;
+#else
+static FLAC__StreamEncoderSeekStatus sf_flac_enc_seek_callback (const FLAC__StreamEncoder *encoder, FLAC__uint64 absolute_byte_offset, void *client_data) ;
+static FLAC__StreamEncoderTellStatus sf_flac_enc_tell_callback (const FLAC__StreamEncoder *encoder, FLAC__uint64 *absolute_byte_offset, void *client_data) ;
+static FLAC__StreamEncoderWriteStatus sf_flac_enc_write_callback (const FLAC__StreamEncoder *encoder, const FLAC__byte buffer [], size_t bytes, unsigned samples, unsigned current_frame, void *client_data) ;
+#endif
 
 static const int legal_sample_rates [] =
 {	8000, 16000, 22050, 24000, 32000, 44100, 48000, 96000
@@ -283,51 +313,99 @@
 } /* flac_buffer_copy */
 
 
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamDecoderReadStatus
 sf_flac_read_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), FLAC__byte buffer [], unsigned *bytes, void *client_data)
+#else
+static FLAC__StreamDecoderReadStatus
+sf_flac_read_callback (const FLAC__StreamDecoder * UNUSED (decoder), FLAC__byte buffer [], size_t *bytes, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	*bytes = psf_fread (buffer, 1, *bytes, psf) ;
 	if (*bytes > 0 && psf->error == 0)
+#ifdef LEGACY_FLAC
 		return FLAC__SEEKABLE_STREAM_DECODER_READ_STATUS_OK ;
 
     return FLAC__SEEKABLE_STREAM_DECODER_READ_STATUS_ERROR ;
+#else
+		return FLAC__STREAM_DECODER_READ_STATUS_CONTINUE ;
+
+    return FLAC__STREAM_DECODER_READ_STATUS_ABORT ;
+#endif
 } /* sf_flac_read_callback */
 
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamDecoderSeekStatus
 sf_flac_seek_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), FLAC__uint64 absolute_byte_offset, void *client_data)
+#else
+static FLAC__StreamDecoderSeekStatus
+sf_flac_seek_callback (const FLAC__StreamDecoder * UNUSED (decoder), FLAC__uint64 absolute_byte_offset, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	psf_fseek (psf, absolute_byte_offset, SEEK_SET) ;
 	if (psf->error)
+#ifdef LEGACY_FLAC
 		return FLAC__SEEKABLE_STREAM_DECODER_SEEK_STATUS_ERROR ;
 
 	return FLAC__SEEKABLE_STREAM_DECODER_SEEK_STATUS_OK ;
+#else
+		return FLAC__STREAM_DECODER_SEEK_STATUS_ERROR ;
+
+	return FLAC__STREAM_DECODER_SEEK_STATUS_OK ;
+#endif
 } /* sf_flac_seek_callback */
 
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamDecoderTellStatus
 sf_flac_tell_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), FLAC__uint64 *absolute_byte_offset, void *client_data)
+#else
+static FLAC__StreamDecoderTellStatus
+sf_flac_tell_callback (const FLAC__StreamDecoder * UNUSED (decoder), FLAC__uint64 *absolute_byte_offset, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	*absolute_byte_offset = psf_ftell (psf) ;
 	if (psf->error)
+#ifdef LEGACY_FLAC
 		return FLAC__SEEKABLE_STREAM_DECODER_TELL_STATUS_ERROR ;
 
 	return FLAC__SEEKABLE_STREAM_DECODER_TELL_STATUS_OK ;
+#else
+		return FLAC__STREAM_DECODER_TELL_STATUS_ERROR ;
+
+	return FLAC__STREAM_DECODER_TELL_STATUS_OK ;
+#endif
 } /* sf_flac_tell_callback */
 
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamDecoderLengthStatus
 sf_flac_length_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), FLAC__uint64 *stream_length, void *client_data)
+#else
+static FLAC__StreamDecoderLengthStatus
+sf_flac_length_callback (const FLAC__StreamDecoder * UNUSED (decoder), FLAC__uint64 *stream_length, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	if ((*stream_length = psf->filelength) == 0)
+#ifdef LEGACY_FLAC
 		return FLAC__SEEKABLE_STREAM_DECODER_LENGTH_STATUS_ERROR ;
 
 	return FLAC__SEEKABLE_STREAM_DECODER_LENGTH_STATUS_OK ;
+#else
+		return FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR ;
+
+	return FLAC__STREAM_DECODER_LENGTH_STATUS_OK ;
+#endif
 } /* sf_flac_length_callback */
 
 static FLAC__bool
+#ifdef LEGACY_FLAC
 sf_flac_eof_callback (const FLAC__SeekableStreamDecoder *UNUSED (decoder), void *client_data)
+#else
+sf_flac_eof_callback (const FLAC__StreamDecoder *UNUSED (decoder), void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	if (psf_ftell (psf) == psf->filelength)
@@ -337,7 +415,11 @@
 } /* sf_flac_eof_callback */
 
 static FLAC__StreamDecoderWriteStatus
+#ifdef LEGACY_FLAC
 sf_flac_write_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), const FLAC__Frame *frame, const FLAC__int32 * const buffer [], void *client_data)
+#else
+sf_flac_write_callback (const FLAC__StreamDecoder * UNUSED (decoder), const FLAC__Frame *frame, const FLAC__int32 * const buffer [], void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 	FLAC_PRIVATE* pflac = (FLAC_PRIVATE*) psf->codec_data ;
 
@@ -353,7 +435,27 @@
 } /* sf_flac_write_callback */
 
 static void
+sf_flac_meta_getvorbiscomment (SF_PRIVATE *psf, int str_type, const FLAC__StreamMetadata *metadata, const char *tag)
+{
+	int i;
+	const char *value, *s;
+
+	i = FLAC__metadata_object_vorbiscomment_find_entry_from(metadata, 0, tag);
+	if (i >= 0) {
+		value = metadata->data.vorbis_comment.comments[i].entry;
+		if ((s = strchr(value, '=')) != NULL)
+			value = s + 1;
+		
+		psf_store_string (psf, str_type, value);
+	}
+}
+
+static void
+#ifdef LEGACY_FLAC
 sf_flac_meta_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), const FLAC__StreamMetadata *metadata, void *client_data)
+#else
+sf_flac_meta_callback (const FLAC__StreamDecoder * UNUSED (decoder), const FLAC__StreamMetadata *metadata, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	switch (metadata->type)
@@ -378,6 +480,10 @@
 				} ;
 			break ;
 
+		case FLAC__METADATA_TYPE_VORBIS_COMMENT :
+			sf_flac_meta_getvorbiscomment (psf, SF_STR_ARTIST, metadata, "artist");
+			sf_flac_meta_getvorbiscomment (psf, SF_STR_TITLE, metadata, "title");
+			break;
 		default :
 			psf_log_printf (psf, "sf_flac_meta_callback : metadata-type %d not yet implemented.\n", metadata->type) ;
 		break ;
@@ -387,7 +493,11 @@
 } /* sf_flac_meta_callback */
 
 static void
+#ifdef LEGACY_FLAC
 sf_flac_error_callback (const FLAC__SeekableStreamDecoder * UNUSED (decoder), FLAC__StreamDecoderErrorStatus status, void *client_data)
+#else
+sf_flac_error_callback (const FLAC__StreamDecoder * UNUSED (decoder), FLAC__StreamDecoderErrorStatus status, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	psf_log_printf (psf, "ERROR : %s\n", FLAC__StreamDecoderErrorStatusString [status]) ;
@@ -407,17 +517,29 @@
 	return ;
 } /* sf_flac_error_callback */
 
+#ifdef LEGACY_FLAC
 static FLAC__SeekableStreamEncoderSeekStatus
 sf_flac_enc_seek_callback (const FLAC__SeekableStreamEncoder * UNUSED (encoder), FLAC__uint64 absolute_byte_offset, void *client_data)
+#else
+static FLAC__StreamEncoderSeekStatus
+sf_flac_enc_seek_callback (const FLAC__StreamEncoder * UNUSED (encoder), FLAC__uint64 absolute_byte_offset, void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	psf_fseek (psf, absolute_byte_offset, SEEK_SET) ;
 	if (psf->error)
+#ifdef LEGACY_FLAC
 		return FLAC__SEEKABLE_STREAM_ENCODER_SEEK_STATUS_ERROR ;
 
     return FLAC__SEEKABLE_STREAM_ENCODER_SEEK_STATUS_OK ;
+#else
+		return FLAC__STREAM_ENCODER_SEEK_STATUS_ERROR ;
+
+    return FLAC__STREAM_ENCODER_SEEK_STATUS_OK ;
+#endif
 } /* sf_flac_enc_seek_callback */
 
+#ifdef LEGACY_FLAC
 #ifdef HAVE_FLAC_1_1_1
 static FLAC__SeekableStreamEncoderTellStatus
 sf_flac_enc_tell_callback (const FLAC__SeekableStreamEncoder *UNUSED (encoder), FLAC__uint64 *absolute_byte_offset, void *client_data)
@@ -430,9 +552,25 @@
 	return FLAC__SEEKABLE_STREAM_ENCODER_TELL_STATUS_OK ;
 } /* sf_flac_enc_tell_callback */
 #endif
+#else
+static FLAC__StreamEncoderTellStatus
+sf_flac_enc_tell_callback (const FLAC__StreamEncoder *UNUSED (encoder), FLAC__uint64 *absolute_byte_offset, void *client_data)
+{	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
+
+	*absolute_byte_offset = psf_ftell (psf) ;
+	if (psf->error)
+		return FLAC__STREAM_ENCODER_TELL_STATUS_ERROR ;
+
+	return FLAC__STREAM_ENCODER_TELL_STATUS_OK ;
+} /* sf_flac_enc_tell_callback */
+#endif
 
 static FLAC__StreamEncoderWriteStatus
+#ifdef LEGACY_FLAC
 sf_flac_enc_write_callback (const FLAC__SeekableStreamEncoder * UNUSED (encoder), const FLAC__byte buffer [], unsigned bytes, unsigned UNUSED (samples), unsigned UNUSED (current_frame), void *client_data)
+#else
+sf_flac_enc_write_callback (const FLAC__StreamEncoder * UNUSED (encoder), const FLAC__byte buffer [], size_t bytes, unsigned UNUSED (samples), unsigned UNUSED (current_frame), void *client_data)
+#endif
 {	SF_PRIVATE *psf = (SF_PRIVATE*) client_data ;
 
 	if (psf_fwrite (buffer, 1, bytes, psf) == bytes && psf->error == 0)
@@ -509,15 +647,27 @@
 		return 0 ;
 
 	if (psf->mode == SFM_WRITE)
-	{	FLAC__seekable_stream_encoder_finish (pflac->fse) ;
+	{
+#ifdef LEGACY_FLAC
+		FLAC__seekable_stream_encoder_finish (pflac->fse) ;
 		FLAC__seekable_stream_encoder_delete (pflac->fse) ;
+#else
+		FLAC__stream_encoder_finish (pflac->fse) ;
+		FLAC__stream_encoder_delete (pflac->fse) ;
+#endif
 		if (pflac->encbuffer)
 			free (pflac->encbuffer) ;
 		} ;
 
 	if (psf->mode == SFM_READ)
-	{	FLAC__seekable_stream_decoder_finish (pflac->fsd) ;
+	{
+#ifdef LEGACY_FLAC
+		FLAC__seekable_stream_decoder_finish (pflac->fsd) ;
 		FLAC__seekable_stream_decoder_delete (pflac->fsd) ;
+#else
+		FLAC__stream_decoder_finish (pflac->fsd) ;
+		FLAC__stream_decoder_delete (pflac->fsd) ;
+#endif
 		} ;
 
 	for (k = 0 ; k < ARRAY_LEN (pflac->rbuffer) ; k++)
@@ -546,17 +696,6 @@
 		return SFE_FLAC_BAD_SAMPLE_RATE ;
 
 	psf_fseek (psf, 0, SEEK_SET) ;
-	if ((pflac->fse = FLAC__seekable_stream_encoder_new ()) == NULL)
-		return SFE_FLAC_NEW_DECODER ;
-	FLAC__seekable_stream_encoder_set_write_callback (pflac->fse, sf_flac_enc_write_callback) ;
-	FLAC__seekable_stream_encoder_set_seek_callback (pflac->fse, sf_flac_enc_seek_callback) ;
-
-#ifdef HAVE_FLAC_1_1_1
-	FLAC__seekable_stream_encoder_set_tell_callback (pflac->fse, sf_flac_enc_tell_callback) ;
-#endif
-	FLAC__seekable_stream_encoder_set_client_data (pflac->fse, psf) ;
-	FLAC__seekable_stream_encoder_set_channels (pflac->fse, psf->sf.channels) ;
-	FLAC__seekable_stream_encoder_set_sample_rate (pflac->fse, psf->sf.samplerate) ;
 
 	switch (psf->sf.format & SF_FORMAT_SUBMASK)
 	{	case SF_FORMAT_PCM_S8 :
@@ -574,12 +713,36 @@
 			break ;
 		} ;
 
+#ifdef LEGACY_FLAC
+	if ((pflac->fse = FLAC__seekable_stream_encoder_new ()) == NULL)
+		return SFE_FLAC_NEW_DECODER ;
+	FLAC__seekable_stream_encoder_set_write_callback (pflac->fse, sf_flac_enc_write_callback) ;
+	FLAC__seekable_stream_encoder_set_seek_callback (pflac->fse, sf_flac_enc_seek_callback) ;
+
+#ifdef HAVE_FLAC_1_1_1
+	FLAC__seekable_stream_encoder_set_tell_callback (pflac->fse, sf_flac_enc_tell_callback) ;
+#endif
+	FLAC__seekable_stream_encoder_set_client_data (pflac->fse, psf) ;
+	FLAC__seekable_stream_encoder_set_channels (pflac->fse, psf->sf.channels) ;
+	FLAC__seekable_stream_encoder_set_sample_rate (pflac->fse, psf->sf.samplerate) ;
 	FLAC__seekable_stream_encoder_set_bits_per_sample (pflac->fse, bps) ;
 
 	if ((bps = FLAC__seekable_stream_encoder_init (pflac->fse)) != FLAC__SEEKABLE_STREAM_DECODER_OK)
 	{	psf_log_printf (psf, "Error : FLAC encoder init returned error : %s\n", FLAC__seekable_stream_encoder_get_resolved_state_string (pflac->fse)) ;
 		return SFE_FLAC_INIT_DECODER ;
 		} ;
+#else
+	if ((pflac->fse = FLAC__stream_encoder_new ()) == NULL)
+		return SFE_FLAC_NEW_DECODER ;
+	FLAC__stream_encoder_set_channels (pflac->fse, psf->sf.channels) ;
+	FLAC__stream_encoder_set_sample_rate (pflac->fse, psf->sf.samplerate) ;
+	FLAC__stream_encoder_set_bits_per_sample (pflac->fse, bps) ;
+
+	if ((bps = FLAC__stream_encoder_init_stream (pflac->fse, sf_flac_enc_write_callback, sf_flac_enc_seek_callback, sf_flac_enc_tell_callback, NULL, psf)) != FLAC__STREAM_DECODER_INIT_STATUS_OK)
+	{	psf_log_printf (psf, "Error : FLAC encoder init returned error : %s\n", FLAC__StreamEncoderInitStatusString[bps]) ;
+		return SFE_FLAC_INIT_DECODER ;
+		} ;
+#endif
 
 	if (psf->error == 0)
 		psf->dataoffset = psf_ftell (psf) ;
@@ -593,6 +756,7 @@
 {	FLAC_PRIVATE* pflac = (FLAC_PRIVATE*) psf->codec_data ;
 
 	psf_fseek (psf, 0, SEEK_SET) ;
+#ifdef LEGACY_FLAC
 	if ((pflac->fsd = FLAC__seekable_stream_decoder_new ()) == NULL)
 		return SFE_FLAC_NEW_DECODER ;
 
@@ -603,6 +767,7 @@
 	FLAC__seekable_stream_decoder_set_eof_callback (pflac->fsd, sf_flac_eof_callback) ;
 	FLAC__seekable_stream_decoder_set_write_callback (pflac->fsd, sf_flac_write_callback) ;
 	FLAC__seekable_stream_decoder_set_metadata_callback (pflac->fsd, sf_flac_meta_callback) ;
+	FLAC__seekable_stream_decoder_set_metadata_respond(pflac->fsd, FLAC__METADATA_TYPE_VORBIS_COMMENT);
 	FLAC__seekable_stream_decoder_set_error_callback (pflac->fsd, sf_flac_error_callback) ;
 	FLAC__seekable_stream_decoder_set_client_data (pflac->fsd, psf) ;
 
@@ -610,9 +775,24 @@
 		return SFE_FLAC_INIT_DECODER ;
 
 	FLAC__seekable_stream_decoder_process_until_end_of_metadata (pflac->fsd) ;
+#else
+	if ((pflac->fsd = FLAC__stream_decoder_new ()) == NULL)
+		return SFE_FLAC_NEW_DECODER ;
+
+	FLAC__stream_decoder_set_metadata_respond(pflac->fsd, FLAC__METADATA_TYPE_VORBIS_COMMENT);
+
+	if (FLAC__stream_decoder_init_stream (pflac->fsd, sf_flac_read_callback, sf_flac_seek_callback, sf_flac_tell_callback, sf_flac_length_callback, sf_flac_eof_callback, sf_flac_write_callback, sf_flac_meta_callback, sf_flac_error_callback, psf) != FLAC__STREAM_DECODER_INIT_STATUS_OK)
+		return SFE_FLAC_INIT_DECODER ;
+
+	FLAC__stream_decoder_process_until_end_of_metadata (pflac->fsd) ;
+#endif
 	if (psf->error == 0)
 	{	FLAC__uint64 position ;
+#ifdef LEGACY_FLAC
 		FLAC__seekable_stream_decoder_get_decode_position (pflac->fsd, &position) ;
+#else
+		FLAC__stream_decoder_get_decode_position (pflac->fsd, &position) ;
+#endif
 		psf->dataoffset = position ;
 		} ;
 
@@ -676,10 +856,18 @@
 		flac_buffer_copy (psf) ;
 
 	while (pflac->pos < pflac->len)
-	{	if (FLAC__seekable_stream_decoder_process_single (pflac->fsd) == 0)
+	{
+#ifdef LEGACY_FLAC
+		if (FLAC__seekable_stream_decoder_process_single (pflac->fsd) == 0)
 			break ;
 		if (FLAC__seekable_stream_decoder_get_state (pflac->fsd) != FLAC__SEEKABLE_STREAM_DECODER_OK)
 			break ;
+#else
+		if (FLAC__stream_decoder_process_single (pflac->fsd) == 0)
+			break ;
+		if (FLAC__stream_decoder_get_state (pflac->fsd) >= FLAC__STREAM_DECODER_END_OF_STREAM)
+			break ;
+#endif
 		} ;
 
 	pflac->ptr = NULL ;
@@ -795,7 +983,11 @@
 	while (len > 0)
 	{	writecount = (len >= bufferlen) ? bufferlen : (int) len ;
 		convert (ptr + total, buffer, writecount) ;
+#ifdef LEGACY_FLAC
 		if (FLAC__seekable_stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#else
+		if (FLAC__stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#endif
 			thiswrite = writecount ;
 		else
 			break ;
@@ -837,7 +1029,11 @@
 	while (len > 0)
 	{	writecount = (len >= bufferlen) ? bufferlen : (int) len ;
 		convert (ptr + total, buffer, writecount) ;
+#ifdef LEGACY_FLAC
 		if (FLAC__seekable_stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#else
+		if (FLAC__stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#endif
 			thiswrite = writecount ;
 		else
 			break ;
@@ -879,7 +1075,11 @@
 	while (len > 0)
 	{	writecount = (len >= bufferlen) ? bufferlen : (int) len ;
 		convert (ptr + total, buffer, writecount, psf->norm_float) ;
+#ifdef LEGACY_FLAC
 		if (FLAC__seekable_stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#else
+		if (FLAC__stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#endif
 			thiswrite = writecount ;
 		else
 			break ;
@@ -1011,7 +1211,11 @@
 	while (len > 0)
 	{	writecount = (len >= bufferlen) ? bufferlen : (int) len ;
 		convert (ptr + total, buffer, writecount, psf->norm_double) ;
+#ifdef LEGACY_FLAC
 		if (FLAC__seekable_stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#else
+		if (FLAC__stream_encoder_process_interleaved (pflac->fse, buffer, writecount/psf->sf.channels))
+#endif
 			thiswrite = writecount ;
 		else
 			break ;
@@ -1131,10 +1335,17 @@
 
 	if (psf->mode == SFM_READ)
 	{	FLAC__uint64 position ;
+#ifdef LEGACY_FLAC
 		if (FLAC__seekable_stream_decoder_seek_absolute (pflac->fsd, offset))
 		{	FLAC__seekable_stream_decoder_get_decode_position (pflac->fsd, &position) ;
 			return offset ;
 			} ;
+#else
+		if (FLAC__stream_decoder_seek_absolute (pflac->fsd, offset))
+		{	FLAC__stream_decoder_get_decode_position (pflac->fsd, &position) ;
+			return offset ;
+			} ;
+#endif
 
 		return ((sf_count_t) -1) ;
 		} ;
