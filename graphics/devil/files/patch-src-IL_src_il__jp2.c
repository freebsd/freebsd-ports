--- src-IL/src/il_jp2.c.orig	2009-03-08 07:10:09 UTC
+++ src-IL/src/il_jp2.c
@@ -459,7 +459,7 @@ static void jas_stream_initbuf(jas_stream_t *stream, i
 			/* The buffer must be large enough to accommodate maximum
 			  putback. */
 			assert(bufsize > JAS_STREAM_MAXPUTBACK);
-			stream->bufbase_ = JAS_CAST(uchar *, buf);
+			stream->bufbase_ = JAS_CAST(jas_uchar *, buf);
 			stream->bufsize_ = bufsize - JAS_STREAM_MAXPUTBACK;
 		}
 	} else {
