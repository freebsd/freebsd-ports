--- src/plugins/avcodec/avcodec.c.orig	2011-10-20 19:26:08 UTC
+++ src/plugins/avcodec/avcodec.c
@@ -1,7 +1,7 @@
 /** @file avcodec.c
  *  Decoder plugin for ffmpeg avcodec formats
  *
- *  Copyright (C) 2006-2011 XMMS2 Team
+ *  Copyright (C) 2006-2014 XMMS2 Team
  *
  *  This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
@@ -14,15 +14,16 @@
  *  Lesser General Public License for more details.
  */
 
-#include "xmms_configuration.h"
-#include "xmms/xmms_xformplugin.h"
-#include "xmms/xmms_sample.h"
-#include "xmms/xmms_log.h"
+#include <xmms_configuration.h>
+#include <xmms/xmms_xformplugin.h>
+#include <xmms/xmms_sample.h>
+#include <xmms/xmms_log.h>
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <glib.h>
+#include <libavutil/mem.h>
 
 #include "avcodec_compat.h"
 
@@ -36,6 +37,8 @@ typedef struct {
 	guint buffer_size;
 	gboolean no_demuxer;
 
+	AVFrame *read_out_frame;
+
 	guint channels;
 	guint samplerate;
 	xmms_sample_format_t sampleformat;
@@ -53,10 +56,14 @@ typedef struct {
 static gboolean xmms_avcodec_plugin_setup (xmms_xform_plugin_t *xform_plugin);
 static gboolean xmms_avcodec_init (xmms_xform_t *xform);
 static void xmms_avcodec_destroy (xmms_xform_t *xform);
+static gint xmms_avcodec_internal_read_some (xmms_xform_t *xform, xmms_avcodec_data_t *data, xmms_error_t *error);
+static gint xmms_avcodec_internal_decode_some (xmms_avcodec_data_t *data);
+static void xmms_avcodec_internal_append (xmms_avcodec_data_t *data);
 static gint xmms_avcodec_read (xmms_xform_t *xform, xmms_sample_t *buf, gint len,
                                xmms_error_t *error);
 static gint64 xmms_avcodec_seek (xmms_xform_t *xform, gint64 samples,
                                  xmms_xform_seek_mode_t whence, xmms_error_t *err);
+static xmms_sample_format_t xmms_avcodec_translate_sample_format (enum AVSampleFormat av_sample_format);
 
 /*
  * Plugin header
@@ -85,13 +92,23 @@ xmms_avcodec_plugin_setup (xmms_xform_pl
 	xmms_magic_add ("A/52 (AC-3) header", "audio/x-ffmpeg-ac3",
 	                "0 beshort 0x0b77", NULL);
 	xmms_magic_add ("DTS header", "audio/x-ffmpeg-dca",
-	                "0 belong 0x7ffe8001", NULL); 
+	                "0 belong 0x7ffe8001", NULL);
 
 	xmms_xform_plugin_indata_add (xform_plugin,
 	                              XMMS_STREAM_TYPE_MIMETYPE,
 	                              "audio/x-ffmpeg-*",
 	                              NULL);
 
+	XMMS_DBG ("avcodec version at build time is %d.%d.%d",
+	          (LIBAVCODEC_VERSION_INT >> 16),
+	          (LIBAVCODEC_VERSION_INT >> 8) & 0xff,
+	          LIBAVCODEC_VERSION_INT & 0xff);
+	XMMS_DBG ("avcodec version at run time is %d.%d.%d",
+	          (avcodec_version() >> 16),
+	          (avcodec_version() >> 8) & 0xff,
+	          avcodec_version() & 0xff);
+	XMMS_DBG ("avcodec configuration is %s", avcodec_configuration());
+
 	return TRUE;
 }
 
@@ -107,6 +124,7 @@ xmms_avcodec_destroy (xmms_xform_t *xfor
 
 	avcodec_close (data->codecctx);
 	av_free (data->codecctx);
+	av_frame_free (&data->read_out_frame);
 
 	g_string_free (data->outbuf, TRUE);
 	g_free (data->buffer);
@@ -132,9 +150,10 @@ xmms_avcodec_init (xmms_xform_t *xform)
 	data->buffer_size = AVCODEC_BUFFER_SIZE;
 	data->codecctx = NULL;
 
+	data->read_out_frame = av_frame_alloc ();
+
 	xmms_xform_private_data_set (xform, data);
 
-	avcodec_init ();
 	avcodec_register_all ();
 
 	mimetype = xmms_xform_indata_get_str (xform,
@@ -161,12 +180,12 @@ xmms_avcodec_init (xmms_xform_t *xform)
 		data->channels = ret;
 	}
 
-	/* bitrate required for WMA files */
+	/* Required by WMA xform. */
 	xmms_xform_auxdata_get_int (xform,
 	                            "bitrate",
 	                            &data->bitrate);
 
-	/* ALAC and MAC require bits per sample field to be 16 */
+	/* Required by tta and apefile xforms. */
 	xmms_xform_auxdata_get_int (xform,
 	                            "samplebits",
 	                            &data->samplebits);
@@ -188,7 +207,8 @@ xmms_avcodec_init (xmms_xform_t *xform)
 		    !strcmp (data->codec_id, "adpcm_swf") ||
 		    !strcmp (data->codec_id, "pcm_s16le") ||
 		    !strcmp (data->codec_id, "ac3") ||
-		    !strcmp (data->codec_id, "dca")) {
+		    !strcmp (data->codec_id, "dca") ||
+		    !strcmp (data->codec_id, "nellymoser")) {
 			/* number 1024 taken from libavformat raw.c RAW_PACKET_SIZE */
 			data->extradata = g_malloc0 (1024);
 			data->extradata_size = 1024;
@@ -196,22 +216,22 @@ xmms_avcodec_init (xmms_xform_t *xform)
 		} else {
 			/* A demuxer plugin forgot to give decoder config? */
 			xmms_log_error ("Decoder config data not found!");
-			return FALSE;
+			goto err;
 		}
 	}
 
-	data->codecctx = avcodec_alloc_context ();
+	data->codecctx = avcodec_alloc_context3 (codec);
 	data->codecctx->sample_rate = data->samplerate;
 	data->codecctx->channels = data->channels;
 	data->codecctx->bit_rate = data->bitrate;
-	CONTEXT_BPS (data->codecctx) = data->samplebits;
+	data->codecctx->bits_per_coded_sample = data->samplebits;
 	data->codecctx->block_align = data->block_align;
 	data->codecctx->extradata = data->extradata;
 	data->codecctx->extradata_size = data->extradata_size;
 	data->codecctx->codec_id = codec->id;
 	data->codecctx->codec_type = codec->type;
 
-	if (avcodec_open (data->codecctx, codec) < 0) {
+	if (avcodec_open2 (data->codecctx, codec, NULL) < 0) {
 		XMMS_DBG ("Opening decoder '%s' failed", codec->name);
 		goto err;
 	} else {
@@ -220,7 +240,7 @@ xmms_avcodec_init (xmms_xform_t *xform)
 
 		/* some codecs need to have something read before they set
 		 * the samplerate and channels correctly, unfortunately... */
-		if ((ret = xmms_avcodec_read (xform, buf, 42, &error)) > 0) {
+		if ((ret = xmms_avcodec_read (xform, buf, sizeof (buf), &error)) > 0) {
 			g_string_insert_len (data->outbuf, 0, buf, ret);
 		} else {
 			XMMS_DBG ("First read failed, codec is not working...");
@@ -231,19 +251,27 @@ xmms_avcodec_init (xmms_xform_t *xform)
 
 	data->samplerate = data->codecctx->sample_rate;
 	data->channels = data->codecctx->channels;
+	data->sampleformat = xmms_avcodec_translate_sample_format (data->codecctx->sample_fmt);
+	if (data->sampleformat == XMMS_SAMPLE_FORMAT_UNKNOWN) {
+		avcodec_close (data->codecctx);
+		goto err;
+	}
 
 	xmms_xform_outdata_type_add (xform,
 	                             XMMS_STREAM_TYPE_MIMETYPE,
 	                             "audio/pcm",
 	                             XMMS_STREAM_TYPE_FMT_FORMAT,
-	                             XMMS_SAMPLE_FORMAT_S16,
+	                             data->sampleformat,
 	                             XMMS_STREAM_TYPE_FMT_CHANNELS,
 	                             data->channels,
 	                             XMMS_STREAM_TYPE_FMT_SAMPLERATE,
 	                             data->samplerate,
 	                             XMMS_STREAM_TYPE_END);
 
-	XMMS_DBG ("Decoder '%s' initialized successfully!", codec->name);
+	XMMS_DBG ("Decoder %s at rate %d with %d channels of format %s initialized",
+	          codec->name, data->codecctx->sample_rate,
+	          data->codecctx->channels,
+	          av_get_sample_fmt_name (data->codecctx->sample_fmt));
 
 	return TRUE;
 
@@ -251,6 +279,9 @@ err:
 	if (data->codecctx) {
 		av_free (data->codecctx);
 	}
+	if (data->read_out_frame) {
+		avcodec_free_frame (&data->read_out_frame);
+	}
 	g_string_free (data->outbuf, TRUE);
 	g_free (data->extradata);
 	g_free (data);
@@ -263,102 +294,24 @@ xmms_avcodec_read (xmms_xform_t *xform, 
                    xmms_error_t *error)
 {
 	xmms_avcodec_data_t *data;
-	char outbuf[AVCODEC_MAX_AUDIO_FRAME_SIZE];
-	gint outbufsize, bytes_read = 0;
 	guint size;
 
 	data = xmms_xform_private_data_get (xform);
 	g_return_val_if_fail (data, -1);
 
-	size = MIN (data->outbuf->len, len);
-	while (size == 0) {
-		AVPacket packet;
-		av_init_packet (&packet);
+	while (0 == (size = MIN (data->outbuf->len, len))) {
+		gint res;
 
 		if (data->no_demuxer || data->buffer_length == 0) {
-			gint read_total;
-
-			bytes_read = xmms_xform_read (xform,
-			                              (gchar *) (data->buffer + data->buffer_length),
-			                              data->buffer_size - data->buffer_length,
-			                              error);
-
-			if (bytes_read < 0) {
-				XMMS_DBG ("Error while reading data");
-				return bytes_read;
-			} else if (bytes_read == 0) {
-				XMMS_DBG ("EOF");
-				return 0;
-			}
-
-			read_total = bytes_read;
-
-			/* If we have a demuxer plugin, make sure we read the whole packet */
-			while (read_total == data->buffer_size && !data->no_demuxer) {
-				/* multiply the buffer size and try to read again */
-				data->buffer = g_realloc (data->buffer, data->buffer_size * 2);
-				bytes_read = xmms_xform_read (xform,
-				                              (gchar *) data->buffer +
-				                                data->buffer_size,
-				                              data->buffer_size,
-				                              error);
-				data->buffer_size *= 2;
-
-				if (bytes_read < 0) {
-					XMMS_DBG ("Error while reading data");
-					return bytes_read;
-				}
-
-				read_total += bytes_read;
-
-				if (read_total < data->buffer_size) {
-					/* finally double the buffer size for performance reasons, the
-					 * hotspot handling likes to fit two frames in the buffer */
-					data->buffer = g_realloc (data->buffer, data->buffer_size * 2);
-					data->buffer_size *= 2;
-					XMMS_DBG ("Reallocated avcodec internal buffer to be %d bytes",
-					          data->buffer_size);
-
-					break;
-				}
-			}
-
-			/* Update the buffer length */
-			data->buffer_length += read_total;
-		}
-
-		packet.data = data->buffer;
-		packet.size = data->buffer_length;
-
-		outbufsize = sizeof (outbuf);
-		bytes_read = avcodec_decode_audio3 (data->codecctx, (short *) outbuf,
-		                                    &outbufsize, &packet);
-
-		/* The DTS decoder of ffmpeg is buggy and always returns
-		 * the input buffer length, get frame length from header */
-		if (!strcmp (data->codec_id, "dca") && bytes_read > 0) {
-			bytes_read = ((int)data->buffer[5] << 12) |
-			             ((int)data->buffer[6] << 4) |
-			             ((int)data->buffer[7] >> 4);
-			bytes_read = (bytes_read & 0x3fff) + 1;
-		}
-
-		if (bytes_read < 0 || bytes_read > data->buffer_length) {
-			XMMS_DBG ("Error decoding data!");
-			return -1;
-		} else if (bytes_read != data->buffer_length) {
-			g_memmove (data->buffer,
-			           data->buffer + bytes_read,
-			           data->buffer_length - bytes_read);
-		}
-
-		data->buffer_length -= bytes_read;
+			gint bytes_read;
 
-		if (outbufsize > 0) {
-			g_string_append_len (data->outbuf, outbuf, outbufsize);
+			bytes_read = xmms_avcodec_internal_read_some (xform, data, error);
+			if (bytes_read <= 0) { return bytes_read; }
 		}
 
-		size = MIN (data->outbuf->len, len);
+		res = xmms_avcodec_internal_decode_some (data);
+		if (res < 0) { return res; }
+		if (res > 0) { xmms_avcodec_internal_append (data); }
 	}
 
 	memcpy (buf, data->outbuf->str, size);
@@ -371,8 +324,6 @@ static gint64
 xmms_avcodec_seek (xmms_xform_t *xform, gint64 samples, xmms_xform_seek_mode_t whence, xmms_error_t *err)
 {
 	xmms_avcodec_data_t *data;
-	char outbuf[AVCODEC_MAX_AUDIO_FRAME_SIZE];
-	gint outbufsize, bytes_read = 0;
 	gint64 ret = -1;
 
 	g_return_val_if_fail (xform, -1);
@@ -390,23 +341,11 @@ xmms_avcodec_seek (xmms_xform_t *xform, 
 
 	/* The buggy ape decoder doesn't flush buffers, so we need to finish decoding
 	 * the frame before seeking to avoid segfaults... this hack sucks */
+	/* FIXME: Is ^^^ still true? */
 	while (data->buffer_length > 0) {
-		AVPacket packet;
-		av_init_packet (&packet);
-		packet.data = data->buffer;
-		packet.size = data->buffer_length;
-
-		outbufsize = sizeof (outbuf);
-		bytes_read = avcodec_decode_audio3 (data->codecctx, (short *) outbuf,
-		                                    &outbufsize, &packet);
-
-		if (bytes_read < 0 || bytes_read > data->buffer_length) {
-			XMMS_DBG ("Error decoding data!");
+		if (xmms_avcodec_internal_decode_some (data) < 0) {
 			return -1;
 		}
-
-		data->buffer_length -= bytes_read;
-		g_memmove (data->buffer, data->buffer + bytes_read, data->buffer_length);
 	}
 
 	ret = xmms_xform_seek (xform, samples, whence, err);
@@ -420,3 +359,178 @@ xmms_avcodec_seek (xmms_xform_t *xform, 
 
 	return ret;
 }
+
+static xmms_sample_format_t
+xmms_avcodec_translate_sample_format (enum AVSampleFormat av_sample_format)
+{
+	switch (av_sample_format) {
+	case AV_SAMPLE_FMT_U8:
+	case AV_SAMPLE_FMT_U8P:
+		return XMMS_SAMPLE_FORMAT_U8;
+	case AV_SAMPLE_FMT_S16:
+	case AV_SAMPLE_FMT_S16P:
+		return XMMS_SAMPLE_FORMAT_S16;
+	case AV_SAMPLE_FMT_S32:
+	case AV_SAMPLE_FMT_S32P:
+		return XMMS_SAMPLE_FORMAT_S32;
+	case AV_SAMPLE_FMT_FLT:
+	case AV_SAMPLE_FMT_FLTP:
+		return XMMS_SAMPLE_FORMAT_FLOAT;
+	case AV_SAMPLE_FMT_DBL:
+	case AV_SAMPLE_FMT_DBLP:
+		return XMMS_SAMPLE_FORMAT_DOUBLE;
+	default:
+		XMMS_DBG ("AVSampleFormat (%i: %s) not supported.", av_sample_format,
+		          av_get_sample_fmt_name (av_sample_format));
+		return XMMS_SAMPLE_FORMAT_UNKNOWN;
+	}
+}
+
+/*
+Read some data from our source of data to data->buffer, updating buffer_length
+and buffer_size as needed.
+
+Returns: on error: negative
+         on EOF: zero
+         otherwise: number of bytes read.
+*/
+static gint
+xmms_avcodec_internal_read_some (xmms_xform_t *xform,
+                                 xmms_avcodec_data_t *data,
+                                 xmms_error_t *error)
+{
+	gint bytes_read, read_total;
+
+	bytes_read = xmms_xform_read (xform,
+	                              (gchar *) (data->buffer + data->buffer_length),
+	                              data->buffer_size - data->buffer_length,
+	                              error);
+
+	if (bytes_read < 0) {
+		XMMS_DBG ("Error while reading data");
+		return bytes_read;
+	} else if (bytes_read == 0) {
+		XMMS_DBG ("EOF");
+		return 0;
+	}
+
+	read_total = bytes_read;
+
+	/* If we have a demuxer plugin, make sure we read the whole packet */
+	while (read_total == data->buffer_size && !data->no_demuxer) {
+		/* multiply the buffer size and try to read again */
+		data->buffer = g_realloc (data->buffer, data->buffer_size * 2);
+		bytes_read = xmms_xform_read (xform,
+		                              (gchar *) data->buffer +
+		                                data->buffer_size,
+		                              data->buffer_size,
+		                              error);
+		data->buffer_size *= 2;
+
+		if (bytes_read < 0) {
+			XMMS_DBG ("Error while reading data");
+			return bytes_read;
+		}
+
+		read_total += bytes_read;
+
+		if (read_total < data->buffer_size) {
+			/* finally double the buffer size for performance reasons, the
+			 * hotspot handling likes to fit two frames in the buffer */
+			data->buffer = g_realloc (data->buffer, data->buffer_size * 2);
+			data->buffer_size *= 2;
+			XMMS_DBG ("Reallocated avcodec internal buffer to be %d bytes",
+			          data->buffer_size);
+
+			break;
+		}
+	}
+
+	/* Update the buffer length */
+	data->buffer_length += read_total;
+
+	return read_total;
+}
+
+/*
+Decode some data from data->buffer[0..data->buffer_length-1] to
+data->read_out_frame
+
+Returns: on error: negative
+         on no new data produced: zero
+         otherwise: positive
+
+FIXME: data->buffer should be at least data->buffer_length +
+FF_INPUT_BUFFER_PADDING_SIZE long.
+*/
+static gint
+xmms_avcodec_internal_decode_some (xmms_avcodec_data_t *data)
+{
+	int got_frame = 0;
+	gint bytes_read = 0;
+	AVPacket packet;
+
+	av_init_packet (&packet);
+	packet.data = data->buffer;
+	packet.size = data->buffer_length;
+
+	/* clear buffers and reset fields to defaults */
+	av_frame_unref (data->read_out_frame);
+
+	bytes_read = avcodec_decode_audio4 (
+		data->codecctx, data->read_out_frame, &got_frame, &packet);
+
+	/* The DTS decoder of ffmpeg is buggy and always returns
+	 * the input buffer length, get frame length from header */
+	/* FIXME: Is ^^^^ still true? */
+	if (!strcmp (data->codec_id, "dca") && bytes_read > 0) {
+		bytes_read = ((int)data->buffer[5] << 12) |
+		             ((int)data->buffer[6] << 4) |
+		             ((int)data->buffer[7] >> 4);
+		bytes_read = (bytes_read & 0x3fff) + 1;
+	}
+
+	if (bytes_read < 0 || bytes_read > data->buffer_length) {
+		XMMS_DBG ("Error decoding data!");
+		return -1;
+	}
+
+	if (bytes_read < data->buffer_length) {
+		data->buffer_length -= bytes_read;
+		g_memmove (data->buffer,
+		           data->buffer + bytes_read,
+		           data->buffer_length);
+	} else {
+		data->buffer_length = 0;
+	}
+
+	return got_frame ? 1 : 0;
+}
+
+static void
+xmms_avcodec_internal_append (xmms_avcodec_data_t *data)
+{
+	enum AVSampleFormat fmt = (enum AVSampleFormat) data->read_out_frame->format;
+	int samples = data->read_out_frame->nb_samples;
+	int channels = data->codecctx->channels;
+	int bps = av_get_bytes_per_sample (fmt);
+
+	if (av_sample_fmt_is_planar (fmt)) {
+		/* Convert from planar to packed format */
+		gint i, j;
+
+		for (i = 0; i < samples; i++) {
+			for (j = 0; j < channels; j++) {
+				g_string_append_len (
+					data->outbuf,
+					(gchar *) (data->read_out_frame->extended_data[j] + i*bps),
+					bps
+				);
+			}
+		}
+	} else {
+		g_string_append_len (data->outbuf,
+		                     (gchar *) data->read_out_frame->extended_data[0],
+		                     samples * channels * bps);
+	}
+}
