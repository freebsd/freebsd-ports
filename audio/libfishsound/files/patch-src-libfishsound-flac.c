--- src/libfishsound/flac.c.orig	2010-02-03 13:34:02 UTC
+++ src/libfishsound/flac.c
@@ -106,7 +106,7 @@ fs_flac_command (FishSound * fsound, int command, void
 #if FS_DECODE
 static FLAC__StreamDecoderReadStatus
 fs_flac_read_callback(const FLAC__StreamDecoder *decoder,
-                      FLAC__byte buffer[], unsigned int *bytes,
+                      FLAC__byte buffer[], size_t *bytes,
                       void *client_data)
 {
   FishSound* fsound = (FishSound*)client_data;
@@ -346,8 +346,8 @@ dec_err:
 #if FS_ENCODE
 static FLAC__StreamEncoderWriteStatus
 fs_flac_enc_write_callback(const FLAC__StreamEncoder *encoder,
-                           const FLAC__byte buffer[], unsigned bytes,
-                           unsigned samples, unsigned current_frame,
+                           const FLAC__byte buffer[], size_t bytes,
+                           uint32_t samples, uint32_t current_frame,
                            void *client_data)
 {
   FishSound* fsound = (FishSound*)client_data;
