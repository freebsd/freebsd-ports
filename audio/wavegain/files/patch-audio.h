--- audio.h.orig	2025-06-08 11:12:29 UTC
+++ audio.h
@@ -136,7 +136,7 @@ long wav_ieee_read(void *, double **buffer, int sample
 long wav_read(void *, double **buffer, int samples, int fast, int chunk);
 long wav_ieee_read(void *, double **buffer, int samples, int fast, int chunk);
 
-enum {
+typedef enum {
 	WAV_NO_FMT = 0,
 	WAV_FMT_8BIT,
 	WAV_FMT_16BIT,
