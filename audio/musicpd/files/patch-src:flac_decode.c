--- src/flac_decode.c	Tue Mar  9 20:29:35 2004
+++ src/flac_decode.c	Tue Mar  9 20:29:59 2004
@@ -188,7 +188,7 @@
 	if(data->dc->seek) return 0;
 
 #ifdef WORDS_BIGENDIAN
-	pcm_changeBufferEndianness(chunk,CHUNK_SIZE,data->af->bits);
+	pcm_changeBufferEndianness(data->chunk,CHUNK_SIZE,data->af->bits);
 #endif
 	memcpy(data->cb->chunks+data->cb->end*CHUNK_SIZE,data->chunk,
 			CHUNK_SIZE);
