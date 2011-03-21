--- ./src/player.c.orig	2003-12-18 22:53:12.000000000 +0100
+++ ./src/player.c	2011-03-21 17:21:19.000000000 +0100
@@ -118,6 +118,7 @@
     char *full_filename;
     long start_position;
 
+    memset(&sound_format, 0, sizeof(sound_format));
     play_state = STATE_BEFORE_SONG;
 
     /* make the compiler happy */
