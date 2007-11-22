--- src/music.c.orig	2007-11-21 18:01:48.000000000 +0100
+++ src/music.c	2007-11-21 18:02:31.000000000 +0100
@@ -393,7 +393,7 @@
 #endif
 #ifdef MID_MUSIC
 	/* MIDI files have the magic four bytes "MThd" */
-	if ( strcmp(magic, "MThd") == 0 ) {
+	if ( strcmp((char *)magic, "MThd") == 0 ) {
 		music->type = MUS_MID;
 		if ( timidity_ok ) {
 			music->data.midi = Timidity_LoadSong((char *)file);
@@ -410,7 +410,7 @@
 #endif
 #ifdef OGG_MUSIC
 	/* Ogg Vorbis files have the magic four bytes "OggS" */
-	if ( strcmp(magic, "OggS") == 0 ) {
+	if ( strcmp((char *)magic, "OggS") == 0 ) {
 		music->type = MUS_OGG;
 		music->data.ogg = OGG_new(file);
 		if ( music->data.ogg == NULL ) {
