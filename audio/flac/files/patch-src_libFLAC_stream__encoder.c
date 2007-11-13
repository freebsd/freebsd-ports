
$FreeBSD$

--- src/libFLAC/stream_encoder.c.orig
+++ src/libFLAC/stream_encoder.c
@@ -50,6 +50,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include "share/alloc.h"
 
 #ifdef min
 #undef min
@@ -836,7 +837,7 @@
 		 */
 		encoder->private_->verify.input_fifo.size = encoder->protected_->blocksize;
 		for(i = 0; i < encoder->protected_->channels; i++) {
-			if(0 == (encoder->private_->verify.input_fifo.data[i] = (FLAC__int32*)malloc(sizeof(FLAC__int32) * encoder->private_->verify.input_fifo.size)))
+			if(0 == (encoder->private_->verify.input_fifo.data[i] = (FLAC__int32*)safe_malloc_mul_2op_(sizeof(FLAC__int32), /*times*/encoder->private_->verify.input_fifo.size)))
 				return encoder->protected_->state = FLAC__STREAM_ENCODER_MEMORY_ALLOCATION_ERROR;
 		}
 		encoder->private_->verify.input_fifo.tail = 0;
