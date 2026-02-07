--- src/player.c.orig	2003-12-18 21:53:12 UTC
+++ src/player.c
@@ -118,6 +118,7 @@ void *player( void *input_data ) {
     char *full_filename;
     long start_position;
 
+    memset(&sound_format, 0, sizeof(sound_format));
     play_state = STATE_BEFORE_SONG;
 
     /* make the compiler happy */
