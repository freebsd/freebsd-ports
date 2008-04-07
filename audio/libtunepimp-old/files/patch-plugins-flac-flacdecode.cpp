--- plugins/flac/flacdecode.cpp.orig	2008-03-28 21:05:11.000000000 +0100
+++ plugins/flac/flacdecode.cpp	2008-03-28 21:08:21.000000000 +0100
@@ -28,6 +28,14 @@
 #include <string.h>
 #include "flacdecode.h"
 
+#include <FLAC/export.h>
+/* FLAC 1.1.3 has FLAC_API_VERSION_CURRENT == 8 */
+#if !defined(FLAC_API_VERSION_CURRENT) || FLAC_API_VERSION_CURRENT < 8
+#define LEGACY_FLAC
+#else
+#undef LEGACY_FLAC
+#endif
+
 void FLAC_errorcb(const FLAC__StreamDecoder * decoder,
                   FLAC__StreamDecoderErrorStatus status, void *client_data)
 {
@@ -99,7 +107,11 @@ FLAC__StreamDecoderWriteStatus FLAC_writ
 
 FLAC__StreamDecoderReadStatus FLAC_readcb(const FLAC__StreamDecoder *decoder, 
                                           FLAC__byte buffer[], 
+#ifdef LEGACY_FLAC
                                           unsigned *bytes, 
+#else
+                                          size_t *bytes, 
+#endif
                                           void *client_data)
 {
    clientdata_t *cd = reinterpret_cast < clientdata_t * >(client_data);
@@ -131,6 +143,7 @@ FlacDecode::FlacDecode(const string & fi
    if (!cd.in)
       return;
 
+#ifdef LEGACY_FLAC
    if (!FLAC__stream_decoder_set_read_callback(decoder, &FLAC_readcb))
       return;
 
@@ -149,6 +162,10 @@ FlacDecode::FlacDecode(const string & fi
    state = FLAC__stream_decoder_init(decoder);
    if (state != FLAC__STREAM_DECODER_SEARCH_FOR_METADATA)
       return;
+#else
+   if (FLAC__stream_decoder_init_stream(decoder, &FLAC_readcb, NULL, NULL, NULL, NULL, &FLAC_writecb, &FLAC_metadatacb, &FLAC_errorcb, &cd) != FLAC__STREAM_DECODER_INIT_STATUS_OK)
+      return;
+#endif
 
    FLAC__stream_decoder_process_until_end_of_metadata(decoder);
    state = FLAC__stream_decoder_get_state(decoder);
@@ -221,6 +238,8 @@ int FlacDecode::read(char *data, int max
           break;
        
        state = FLAC__stream_decoder_get_state(decoder);
+       if (state == FLAC__STREAM_DECODER_END_OF_STREAM)
+           break;
        if (state != FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC ||
            state != FLAC__STREAM_DECODER_READ_FRAME)
        {
