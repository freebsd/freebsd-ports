
$FreeBSD$

--- src/libFLAC/bitbuffer.c.orig
+++ src/libFLAC/bitbuffer.c
@@ -35,6 +35,7 @@
 #include "private/bitmath.h"
 #include "private/crc.h"
 #include "FLAC/assert.h"
+#include "share/alloc.h"
 
 /*
  * Along the way you will see two versions of some functions, selected
@@ -193,7 +194,7 @@
 	if(bb->capacity == new_capacity)
 		return true;
 
-	new_buffer = (FLAC__blurb*)calloc(new_capacity, sizeof(FLAC__blurb));
+	new_buffer = (FLAC__blurb*)safe_calloc_(new_capacity, sizeof(FLAC__blurb));
 	if(new_buffer == 0)
 		return false;
 	memcpy(new_buffer, bb->buffer, sizeof(FLAC__blurb)*min(bb->blurbs+(bb->bits?1:0), new_capacity));
@@ -425,7 +426,7 @@
 {
 	if(bb->buffer == 0) {
 		bb->capacity = FLAC__BITBUFFER_DEFAULT_CAPACITY;
-		bb->buffer = (FLAC__blurb*)calloc(bb->capacity, sizeof(FLAC__blurb));
+		bb->buffer = (FLAC__blurb*)safe_calloc_(bb->capacity, sizeof(FLAC__blurb));
 		if(bb->buffer == 0)
 			return false;
 	}
