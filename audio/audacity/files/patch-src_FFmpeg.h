--- src/FFmpeg.h.orig	2015-03-02 01:06:57 UTC
+++ src/FFmpeg.h
@@ -688,7 +688,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       AVOutputFormat*,
       av_oformat_next,
-      (AVOutputFormat *f),
+      (const AVOutputFormat *f),
       (f)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
@@ -755,7 +755,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       int,
       av_fifo_size,
-      (AVFifoBuffer *f),
+      (const AVFifoBuffer *f),
       (f)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
@@ -801,7 +801,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       AVDictionaryEntry *,
       av_dict_get,
-      (AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags),
+      (const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags),
       (m, key, prev, flags)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
