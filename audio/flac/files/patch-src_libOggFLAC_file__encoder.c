
$FreeBSD$

--- src/libOggFLAC/file_encoder.c.orig
+++ src/libOggFLAC/file_encoder.c
@@ -35,6 +35,7 @@
 #include "FLAC/assert.h"
 #include "OggFLAC/seekable_stream_encoder.h"
 #include "protected/file_encoder.h"
+#include "share/alloc.h"
 
 #ifdef max
 #undef max
@@ -450,7 +451,7 @@
 		free(encoder->private_->filename);
 		encoder->private_->filename = 0;
 	}
-	if(0 == (encoder->private_->filename = (char*)malloc(strlen(value)+1))) {
+	if(0 == (encoder->private_->filename = (char*)safe_malloc_add_2op_(strlen(value), /*+*/1))) {
 		encoder->protected_->state = OggFLAC__FILE_ENCODER_MEMORY_ALLOCATION_ERROR;
 		return false;
 	}
