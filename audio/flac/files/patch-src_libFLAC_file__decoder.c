
$FreeBSD$

--- src/libFLAC/file_decoder.c.orig
+++ src/libFLAC/file_decoder.c
@@ -43,6 +43,7 @@
 #include "FLAC/assert.h"
 #include "protected/file_decoder.h"
 #include "protected/seekable_stream_decoder.h"
+#include "share/alloc.h"
 
 /***********************************************************************
  *
@@ -248,7 +249,7 @@
 		decoder->private_->filename = 0;
 	}
 	if(0 != strcmp(value, "-")) {
-		if(0 == (decoder->private_->filename = (char*)malloc(strlen(value)+1))) {
+		if(0 == (decoder->private_->filename = (char*)safe_malloc_add_2op_(strlen(value), /*+*/1))) {
 			decoder->protected_->state = FLAC__FILE_DECODER_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
