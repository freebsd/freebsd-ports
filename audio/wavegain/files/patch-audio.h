--- audio.h.orig	2008-11-11 11:29:08 UTC
+++ audio.h
@@ -118,7 +118,7 @@ void raw_close(void *);
 long wav_read(void *, double **buffer, int samples, int fast, int chunk);
 long wav_ieee_read(void *, double **buffer, int samples, int fast, int chunk);
 
-enum {
+typedef enum {
 	WAV_NO_FMT = 0,
 	WAV_FMT_8BIT,
 	WAV_FMT_16BIT,
