
$FreeBSD$

--- src/libFLAC/file_encoder.c.orig
+++ src/libFLAC/file_encoder.c
@@ -34,6 +34,7 @@
 #include <string.h> /* for strlen(), strcpy() */
 #include "FLAC/assert.h"
 #include "protected/file_encoder.h"
+#include "share/alloc.h"
 
 #ifdef max
 #undef max
@@ -436,7 +437,7 @@
 		free(encoder->private_->filename);
 		encoder->private_->filename = 0;
 	}
-	if(0 == (encoder->private_->filename = (char*)malloc(strlen(value)+1))) {
+	if(0 == (encoder->private_->filename = (char*)safe_malloc_add_2op_(strlen(value), /*+*/1))) {
 		encoder->protected_->state = FLAC__FILE_ENCODER_MEMORY_ALLOCATION_ERROR;
 		return false;
 	}
