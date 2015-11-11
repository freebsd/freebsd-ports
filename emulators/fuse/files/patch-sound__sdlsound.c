--- sound/sdlsound.c.orig	2013-05-16 20:26:12 UTC
+++ sound/sdlsound.c
@@ -94,7 +94,9 @@ sound_lowlevel_init( const char *device,
      speed to about 2000% on my Mac, 100Hz allows up to 5000% for me) */
   if( hz > 100.0 ) hz = 100.0;
   sound_framesiz = *freqptr / hz;
-  requested.samples = sound_framesiz;
+  requested.samples = 1;
+  while( requested.samples < sound_framesiz )
+    requested.samples *= 2;
 
   if ( SDL_OpenAudio( &requested, &received ) < 0 ) {
     settings_current.sound = 0;
@@ -112,7 +114,9 @@ sound_lowlevel_init( const char *device,
 
     requested.freq = *freqptr;
     sound_framesiz = *freqptr / hz;
-    requested.samples = sound_framesiz;
+    requested.samples = 1;
+    while( requested.samples < sound_framesiz )
+      requested.samples *= 2;
 
     if( SDL_OpenAudio( &requested, NULL ) < 0 ) {
       settings_current.sound = 0;
