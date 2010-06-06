
$FreeBSD$

--- src/player.c.orig
+++ src/player.c
@@ -118,6 +118,7 @@
     char *full_filename;
     long start_position;
 
+    memset(&sound_format, 0, sizeof(sound_format));
     play_state = STATE_BEFORE_SONG;
 
     /* make the compiler happy */
