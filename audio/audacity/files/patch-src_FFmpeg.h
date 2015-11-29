--- src/FFmpeg.h.orig	2015-07-11 10:02:22 UTC
+++ src/FFmpeg.h
@@ -689,7 +689,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       AVOutputFormat*,
       av_oformat_next,
-      (AVOutputFormat *f),
+      (const AVOutputFormat *f),
       (f)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
@@ -756,7 +756,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       int,
       av_fifo_size,
-      (AVFifoBuffer *f),
+      (const AVFifoBuffer *f),
       (f)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
@@ -802,7 +802,7 @@ extern "C" {
    FFMPEG_FUNCTION_WITH_RETURN(
       AVDictionaryEntry *,
       av_dict_get,
-      (AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags),
+      (const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags),
       (m, key, prev, flags)
    );
    FFMPEG_FUNCTION_WITH_RETURN(
