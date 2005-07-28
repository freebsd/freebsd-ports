--- decoder_plugins/flac/flac.c.orig	Fri Jul 29 01:31:54 2005
+++ decoder_plugins/flac/flac.c	Fri Jul 29 01:32:11 2005
@@ -422,11 +422,12 @@
 static int flac_seek (void *void_data, int sec)
 {
 	struct flac_data *data = (struct flac_data *)void_data;
+	FLAC__uint64 target_sample;
 
 	if (sec < 0 || (unsigned)sec > data->length)
 		return -1;
 
-	FLAC__uint64 target_sample = (FLAC__uint64)((sec/(double)data->length)
+	target_sample = (FLAC__uint64)((sec/(double)data->length)
 			* (double)data->total_samples);
 	
 	if (FLAC__seekable_stream_decoder_seek_absolute(data->decoder,
