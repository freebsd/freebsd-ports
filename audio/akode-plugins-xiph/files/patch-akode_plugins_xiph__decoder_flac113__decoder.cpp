--- akode/plugins/xiph_decoder/flac113_decoder.cpp.orig	2008-03-27 16:11:26.000000000 +0100
+++ akode/plugins/xiph_decoder/flac113_decoder.cpp	2008-03-27 16:11:46.000000000 +0100
@@ -108,7 +108,7 @@ struct FLACDecoder::private_data {
 static FLAC__StreamDecoderReadStatus flac_read_callback(
         const FLAC__StreamDecoder *,
         FLAC__byte buffer[],
-        unsigned *bytes,
+        size_t *bytes,
         void *client_data)
 {
     FLACDecoder::private_data *data = (FLACDecoder::private_data*)client_data;
