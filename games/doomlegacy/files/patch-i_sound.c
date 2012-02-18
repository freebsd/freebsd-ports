--- sdl/i_sound.c.orig	2004-04-18 23:02:24.000000000 +0200
+++ sdl/i_sound.c	2012-02-04 08:58:36.000000000 +0100
@@ -118,7 +118,7 @@
 
 #define SAMPLERATE              11025   // Hz
 
-static int samplecount = 512;
+static int samplecount = 1024;
 
 static int lengths[NUMSFX];     // The actual lengths of all sound effects.
 static unsigned int channelstep[NUM_CHANNELS];  // The channel step amount...
@@ -517,12 +517,12 @@
     // Mixing channel index.
     int chan;
 
-    extern void music_mixer(void *udata, Uint8 * stream, int len);
+    //extern void music_mixer(void *udata, Uint8 * stream, int len);
 
     if (nosound)
         return;
     // Mix in the music
-    music_mixer(NULL, stream, len);
+    //music_mixer(NULL, stream, len);
 
     if (nosound)
         return;
@@ -709,14 +709,15 @@
     /*
        Should this be exposed in mixer.h?
      */
-    extern void close_music(void);
+    //extern void close_music(void);
     if (nomusic)
         return;
 
     if (!musicStarted)
         return;
 
-    close_music();
+    //close_music();
+    Mix_CloseAudio();
 
     CONS_Printf("I_ShutdownMusic: shut down\n");
     musicStarted = false;
@@ -740,7 +741,8 @@
     if (nomusic)
         return;
 
-    if (open_music(&audio) < 0)
+    //if (open_music(&audio) < 0)
+    if (Mix_OpenAudio (audio.freq, audio.format, audio.channels, audio.samples) < 0)
     {
         CONS_Printf("Unable to open music: %s\n", Mix_GetError());
         nomusic = true;
