--- cmd/ossplay/ossplay_parser.c.bak	2009-09-03 06:14:34.000000000 -0400
+++ cmd/ossplay/ossplay_parser.c	2009-09-22 15:17:49.000000000 -0400
@@ -91,7 +91,7 @@
     {
       *vft = (dlopen_funcs_t *)ossplay_malloc (sizeof (dlopen_funcs_t));
 
-      (*vft)->vorbisfile_handle = ossplay_dlopen ("libvorbisfile.so.3");
+      (*vft)->vorbisfile_handle = ossplay_dlopen ("libvorbisfile.so.6");
 
       if ((*vft)->vorbisfile_handle == NULL)
         {
