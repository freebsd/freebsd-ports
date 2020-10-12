--- src/gallium/auxiliary/vl/vl_stubs.c.orig	2020-09-23 21:12:53 UTC
+++ src/gallium/auxiliary/vl/vl_stubs.c
@@ -140,6 +140,14 @@ vl_create_mpeg12_decoder(struct pipe_context *pipe,
    return NULL;
 }
 
+struct pipe_video_buffer *
+vl_video_buffer_create_as_resource(struct pipe_context *pipe,
+                                   const struct pipe_video_buffer *tmpl)
+{
+   assert(0);
+   return NULL;
+}
+
 /*
  * vl_zscan
  */
