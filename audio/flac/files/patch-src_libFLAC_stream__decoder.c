--- src/libFLAC/stream_decoder.c.orig	2013-05-26 09:30:33 UTC
+++ src/libFLAC/stream_decoder.c
@@ -71,7 +71,7 @@ FLAC_API int FLAC_API_SUPPORTS_OGG_FLAC 
  *
  ***********************************************************************/
 
-static FLAC__byte ID3V2_TAG_[3] = { 'I', 'D', '3' };
+static const FLAC__byte ID3V2_TAG_[3] = { 'I', 'D', '3' };
 
 /***********************************************************************
  *
@@ -1365,6 +1365,10 @@ FLAC__bool find_metadata_(FLAC__StreamDe
 			id = 0;
 			continue;
 		}
+
+		if(id >= 3)
+			return false;
+
 		if(x == ID3V2_TAG_[id]) {
 			id++;
 			i = 0;
@@ -2705,7 +2709,8 @@ FLAC__bool read_residual_partitioned_ric
 		if(decoder->private_->frame.header.blocksize < predictor_order) {
 			send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
 			decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
-			return true;
+			/* We have received a potentially malicious bt stream. All we can do is error out to avoid a heap overflow. */
+			return false;
 		}
 	}
 	else {
