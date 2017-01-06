Cast to correct types for chromaprint >= 1.4

--- groovefingerprinter/fingerprinter.c.orig	2015-05-26 01:32:01 UTC
+++ groovefingerprinter/fingerprinter.c
@@ -64,7 +64,11 @@ static int emit_track_info(struct Groove
         return -1;
     }
     if (!chromaprint_get_raw_fingerprint(p->chroma_ctx,
+#if CHROMAPRINT_VERSION_MAJOR > 1 || CHROMAPRINT_VERSION_MINOR >= 4
+                (uint32_t**)&info->fingerprint, &info->fingerprint_size))
+#else
                 (void**)&info->fingerprint, &info->fingerprint_size))
+#endif
     {
         av_log(NULL, AV_LOG_ERROR, "unable to get fingerprint\n");
         return -1;
@@ -141,7 +145,11 @@ static void *print_thread(void *arg) {
         double buffer_duration = buffer->frame_count / (double)buffer->format.sample_rate;
         p->track_duration += buffer_duration;
         p->album_duration += buffer_duration;
+#if CHROMAPRINT_VERSION_MAJOR > 1 || CHROMAPRINT_VERSION_MINOR >= 4
+        if (!chromaprint_feed(p->chroma_ctx, (const int16_t*)buffer->data[0], buffer->frame_count * 2)) {
+#else
         if (!chromaprint_feed(p->chroma_ctx, buffer->data[0], buffer->frame_count * 2)) {
+#endif
             av_log(NULL, AV_LOG_ERROR, "unable to feed fingerprint\n");
         }
 
@@ -387,7 +395,11 @@ void groove_fingerprinter_free_info(stru
 
 int groove_fingerprinter_encode(int32_t *fp, int size, char **encoded_fp) {
     int encoded_size;
+#if CHROMAPRINT_VERSION_MAJOR > 1 || CHROMAPRINT_VERSION_MINOR >= 4
+    int err = chromaprint_encode_fingerprint((const uint32_t*)fp, size,
+#else
     int err = chromaprint_encode_fingerprint(fp, size,
+#endif
             CHROMAPRINT_ALGORITHM_DEFAULT, (void*)encoded_fp, &encoded_size, 1);
     return err == 1 ? 0 : -1;
 }
@@ -395,7 +407,11 @@ int groove_fingerprinter_encode(int32_t 
 int groove_fingerprinter_decode(char *encoded_fp, int32_t **fp, int *size) {
     int algorithm;
     int encoded_size = strlen(encoded_fp);
+#if CHROMAPRINT_VERSION_MAJOR > 1 || CHROMAPRINT_VERSION_MINOR >= 4
+    int err = chromaprint_decode_fingerprint(encoded_fp, encoded_size, (uint32_t**)fp, size,
+#else
     int err = chromaprint_decode_fingerprint(encoded_fp, encoded_size, (void**)fp, size,
+#endif
             &algorithm, 1);
     return err == 1 ? 0 : -1;
 }
