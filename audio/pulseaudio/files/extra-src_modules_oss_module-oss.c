--- src/modules/oss/module-oss.c.orig	2010-11-26 01:45:23.000000000 +0100
+++ src/modules/oss/module-oss.c	2011-03-11 10:14:04.000000000 +0100
@@ -1164,7 +1164,7 @@ int pa__init(pa_module*m) {
     int fd = -1;
     int nfrags, orig_frag_size, frag_size;
     int mode, caps;
-    pa_bool_t record = TRUE, playback = TRUE, use_mmap = TRUE;
+    pa_bool_t record = TRUE, playback = TRUE, use_mmap = FALSE;
     pa_sample_spec ss;
     pa_channel_map map;
     pa_modargs *ma = NULL;
