$FreeBSD$

--- cstream.cc.orig	Fri Jun  7 21:58:54 2002
+++ cstream.cc	Fri Jun  7 21:59:01 2002
@@ -26,7 +26,7 @@
 
 #include <string.h>
 
-void	ht_compressed_stream::init(ht_stream *stream, bool own_stream, UINT granularity=COMPRESSED_STREAM_DEFAULT_GRANULARITY)
+void	ht_compressed_stream::init(ht_stream *stream, bool own_stream, UINT granularity)
 {
 	ht_layer_stream::init(stream, own_stream);
 	if ((get_access_mode() & (FAM_READ | FAM_WRITE)) == (FAM_READ | FAM_WRITE)) {
