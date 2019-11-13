Obtained from:	https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=508133#15

--- layer3.c.orig	2004-01-23 09:41:32 UTC
+++ layer3.c
@@ -2608,6 +2608,12 @@ int mad_layer_III(struct mad_stream *str
     next_md_begin = 0;
 
   md_len = si.main_data_begin + frame_space - next_md_begin;
+  if (md_len + MAD_BUFFER_GUARD > MAD_BUFFER_MDLEN)
+  {
+	stream->error = MAD_ERROR_LOSTSYNC;
+	stream->sync = 0;
+	return -1;
+  }
 
   frame_used = 0;
 
