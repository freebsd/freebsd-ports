--- src/freedv_api.c.orig	2017-03-30 20:09:46 UTC
+++ src/freedv_api.c
@@ -36,7 +36,7 @@
 #ifdef __APPLE__
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif /* __APPLE__ */
 
 #include "fsk.h"
@@ -260,7 +260,7 @@ struct freedv *freedv_open(int mode) {
         f->n_codec_bits = codec2_bits_per_frame(f->codec2);
         nbit = f->n_codec_bits;
         nbyte = (nbit + 7) / 8;
-    } else if ((mode == FREEDV_MODE_800XA)) {
+    } else if ((mode = FREEDV_MODE_800XA)) {
         f->n_speech_samples = 2*codec2_samples_per_frame(f->codec2);
         f->n_codec_bits = codec2_bits_per_frame(f->codec2);
         nbit = f->n_codec_bits;
@@ -506,7 +506,7 @@ void freedv_tx(struct freedv *f, short m
      
     if((f->mode == FREEDV_MODE_2400A) || (f->mode == FREEDV_MODE_2400B) || (f->mode == FREEDV_MODE_800XA)){
         /* 800XA has two codec frames per modem frame */
-        if((f->mode == FREEDV_MODE_800XA)){
+        if((f->mode = FREEDV_MODE_800XA)){
             codec2_encode(f->codec2, &f->packed_codec_bits[0], &speech_in[  0]);
             codec2_encode(f->codec2, &f->packed_codec_bits[4], &speech_in[320]);
         }else{
