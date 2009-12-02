--- ./audacious-dumb.c.orig	2009-12-02 00:14:15.000000000 +0100
+++ ./audacious-dumb.c	2009-12-02 00:14:26.000000000 +0100
@@ -49,7 +49,7 @@
     .stop = stop,
     .pause = duh_pause,
     .seek = seek,
-    .get_song_info = get_song_info,
+    NULL,
     .file_info_box = file_info_box,
     .get_song_tuple = get_tuple_info,
     .is_our_file_from_vfs = is_our_file_from_vfs,
