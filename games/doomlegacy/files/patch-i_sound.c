--- sdl/i_sound.c.orig	Mon Apr 19 01:02:24 2004
+++ sdl/i_sound.c	Sat Mar  5 23:04:27 2005
@@ -118,7 +118,7 @@
 
 #define SAMPLERATE              11025   // Hz
 
-static int samplecount = 512;
+static int samplecount = 1024;
 
 static int lengths[NUMSFX];     // The actual lengths of all sound effects.
 static unsigned int channelstep[NUM_CHANNELS];  // The channel step amount...
