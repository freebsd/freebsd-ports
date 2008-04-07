--- decoders/flac.c.orig	2003-03-10 23:44:14.000000000 +0100
+++ decoders/flac.c	2008-03-27 21:35:30.000000000 +0100
@@ -44,42 +44,33 @@
 #define __SDL_SOUND_INTERNAL__
 #include "SDL_sound_internal.h"
 
-#include <FLAC/seekable_stream_decoder.h>
+#include <FLAC/stream_decoder.h>
 
-#define D_END_OF_STREAM               FLAC__SEEKABLE_STREAM_DECODER_END_OF_STREAM
+#define D_END_OF_STREAM               FLAC__STREAM_DECODER_END_OF_STREAM
 
-#define d_new()                       FLAC__seekable_stream_decoder_new()
-#define d_init(x)                     FLAC__seekable_stream_decoder_init(x)
-#define d_process_metadata(x)         FLAC__seekable_stream_decoder_process_until_end_of_metadata(x)
-#define d_process_one_frame(x)        FLAC__seekable_stream_decoder_process_single(x)
-#define d_get_state(x)                FLAC__seekable_stream_decoder_get_state(x)
-#define d_finish(x)                   FLAC__seekable_stream_decoder_finish(x)
-#define d_delete(x)                   FLAC__seekable_stream_decoder_delete(x)
-#define d_set_read_callback(x, y)     FLAC__seekable_stream_decoder_set_read_callback(x, y)
-#define d_set_write_callback(x, y)    FLAC__seekable_stream_decoder_set_write_callback(x, y)
-#define d_set_metadata_callback(x, y) FLAC__seekable_stream_decoder_set_metadata_callback(x, y)
-#define d_set_error_callback(x, y)    FLAC__seekable_stream_decoder_set_error_callback(x, y)
-#define d_set_client_data(x, y)       FLAC__seekable_stream_decoder_set_client_data(x, y)
-
-typedef FLAC__SeekableStreamDecoder           decoder_t;
-typedef FLAC__SeekableStreamDecoderReadStatus d_read_status_t;
-
-#define D_SEEK_STATUS_OK              FLAC__SEEKABLE_STREAM_DECODER_SEEK_STATUS_OK
-#define D_SEEK_STATUS_ERROR           FLAC__SEEKABLE_STREAM_DECODER_SEEK_STATUS_ERROR
-#define D_TELL_STATUS_OK              FLAC__SEEKABLE_STREAM_DECODER_TELL_STATUS_OK
-#define D_TELL_STATUS_ERROR           FLAC__SEEKABLE_STREAM_DECODER_TELL_STATUS_ERROR
-#define D_LENGTH_STATUS_OK            FLAC__SEEKABLE_STREAM_DECODER_LENGTH_STATUS_OK
-#define D_LENGTH_STATUS_ERROR         FLAC__SEEKABLE_STREAM_DECODER_LENGTH_STATUS_ERROR
-
-#define d_set_seek_callback(x, y)     FLAC__seekable_stream_decoder_set_seek_callback(x, y)
-#define d_set_tell_callback(x, y)     FLAC__seekable_stream_decoder_set_tell_callback(x, y)
-#define d_set_length_callback(x, y)   FLAC__seekable_stream_decoder_set_length_callback(x, y)
-#define d_set_eof_callback(x, y)      FLAC__seekable_stream_decoder_set_eof_callback(x, y)
-#define d_seek_absolute(x, y)         FLAC__seekable_stream_decoder_seek_absolute(x, y)
-
-typedef FLAC__SeekableStreamDecoderSeekStatus   d_seek_status_t;
-typedef FLAC__SeekableStreamDecoderTellStatus   d_tell_status_t;
-typedef FLAC__SeekableStreamDecoderLengthStatus d_length_status_t;
+#define d_new()                       FLAC__stream_decoder_new()
+#define d_init(a,b,c,d,e,f,g,h,i,j)   FLAC__stream_decoder_init_stream(a,b,c,d,e,f,g,h,i,j)
+#define d_process_metadata(x)         FLAC__stream_decoder_process_until_end_of_metadata(x)
+#define d_process_one_frame(x)        FLAC__stream_decoder_process_single(x)
+#define d_get_state(x)                FLAC__stream_decoder_get_state(x)
+#define d_finish(x)                   FLAC__stream_decoder_finish(x)
+#define d_delete(x)                   FLAC__stream_decoder_delete(x)
+
+typedef FLAC__StreamDecoder           decoder_t;
+typedef FLAC__StreamDecoderReadStatus d_read_status_t;
+
+#define D_SEEK_STATUS_OK              FLAC__STREAM_DECODER_SEEK_STATUS_OK
+#define D_SEEK_STATUS_ERROR           FLAC__STREAM_DECODER_SEEK_STATUS_ERROR
+#define D_TELL_STATUS_OK              FLAC__STREAM_DECODER_TELL_STATUS_OK
+#define D_TELL_STATUS_ERROR           FLAC__STREAM_DECODER_TELL_STATUS_ERROR
+#define D_LENGTH_STATUS_OK            FLAC__STREAM_DECODER_LENGTH_STATUS_OK
+#define D_LENGTH_STATUS_ERROR         FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR
+
+#define d_seek_absolute(x, y)         FLAC__stream_decoder_seek_absolute(x, y)
+
+typedef FLAC__StreamDecoderSeekStatus   d_seek_status_t;
+typedef FLAC__StreamDecoderTellStatus   d_tell_status_t;
+typedef FLAC__StreamDecoderLengthStatus d_length_status_t;
 
 #define D_WRITE_CONTINUE     FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE
 #define D_READ_END_OF_STREAM FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM
@@ -400,17 +391,6 @@
         BAIL_MACRO(ERR_OUT_OF_MEMORY, 0);
     } /* if */       
 
-    d_set_read_callback(decoder, read_callback);
-    d_set_write_callback(decoder, write_callback);
-    d_set_metadata_callback(decoder, metadata_callback);
-    d_set_error_callback(decoder, error_callback);
-    d_set_seek_callback(decoder, seek_callback);
-    d_set_tell_callback(decoder, tell_callback);
-    d_set_length_callback(decoder, length_callback);
-    d_set_eof_callback(decoder, eof_callback);
-
-    d_set_client_data(decoder, f);
-
     f->rw = internal->rw;
     f->sample = sample;
     f->decoder = decoder;
@@ -418,7 +398,9 @@
     f->is_flac = 0 /* !!! FIXME: should be "has_extension", not "0". */;
 
     internal->decoder_private = f;
-    d_init(decoder);
+    d_init(decoder, read_callback, seek_callback, tell_callback,
+        length_callback, eof_callback, write_callback, metadata_callback,
+        error_callback, f);
 
     sample->flags = SOUND_SAMPLEFLAG_NONE;
 
