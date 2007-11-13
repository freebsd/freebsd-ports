
$FreeBSD$

--- src/libFLAC/md5.c.orig
+++ src/libFLAC/md5.c
@@ -31,6 +31,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include "share/alloc.h"
 
 #ifndef FLaC__INLINE
 #define FLaC__INLINE
@@ -230,13 +231,19 @@
 	unsigned channel, sample, a_byte;
 	FLAC__int32 a_word;
 	FLAC__byte *buf_;
-	const unsigned bytes_needed = channels * samples * bytes_per_sample;
+	const size_t bytes_needed = (size_t)channels * (size_t)samples * (size_t)bytes_per_sample;
+
+	/* overflow check */
+	if((size_t)channels > SIZE_MAX / (size_t)bytes_per_sample)
+		return false;
+	if((size_t)channels * (size_t)bytes_per_sample > SIZE_MAX / (size_t)samples)
+		return false;
 
 	if(ctx->capacity < bytes_needed) {
 		FLAC__byte *tmp = (FLAC__byte*)realloc(ctx->internal_buf, bytes_needed);
 		if(0 == tmp) {
 			free(ctx->internal_buf);
-			if(0 == (ctx->internal_buf = (FLAC__byte*)malloc(bytes_needed)))
+			if(0 == (ctx->internal_buf = (FLAC__byte*)safe_malloc_(bytes_needed)))
 				return false;
 		}
 		ctx->internal_buf = tmp;
