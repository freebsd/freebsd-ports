
$FreeBSD$

--- src/libOggFLAC/ogg_helper.c.orig
+++ src/libOggFLAC/ogg_helper.c
@@ -34,6 +34,7 @@
 #include "FLAC/assert.h"
 #include "private/ogg_helper.h"
 #include "protected/seekable_stream_encoder.h"
+#include "share/alloc.h"
 
 
 static FLAC__bool full_read_(OggFLAC__SeekableStreamEncoder *encoder, FLAC__byte *buffer, unsigned bytes, OggFLAC__SeekableStreamEncoderReadCallback read_callback, void *client_data)
@@ -102,7 +103,7 @@
 	}
 
 	/* allocate space for the page header */
-	if(0 == (page->header = (unsigned char *)malloc(OGG_MAX_HEADER_LEN))) {
+	if(0 == (page->header = (unsigned char *)safe_malloc_(OGG_MAX_HEADER_LEN))) {
 		encoder->protected_->state = OggFLAC__SEEKABLE_STREAM_ENCODER_MEMORY_ALLOCATION_ERROR;
 		return false;
 	}
@@ -144,7 +145,7 @@
 	}
 
 	/* allocate space for the page body */
-	if(0 == (page->body = (unsigned char *)malloc(page->body_len))) {
+	if(0 == (page->body = (unsigned char *)safe_malloc_(page->body_len))) {
 		encoder->protected_->state = OggFLAC__SEEKABLE_STREAM_ENCODER_MEMORY_ALLOCATION_ERROR;
 		return false;
 	}
