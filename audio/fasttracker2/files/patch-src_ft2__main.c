--- src/ft2_main.c.orig	2018-11-23 22:42:23 UTC
+++ src/ft2_main.c
@@ -205,13 +205,14 @@ int main(int argc, char *argv[])
     //benchmarkAudioChannelMixer(); /* for development testing */
 
     /* set up MIDI input (in a thread because it can take quite a while on f.ex. macOS) */
-    
+    /*
     initMidiThread = SDL_CreateThread(initMidiFunc, "FT2 Clone MIDI Initialization Thread", NULL);
     if (initMidiThread == NULL)
     {
         cleanUpAndExit();
         return (1);
     }
+    */
 
     /* don't let thread wait for this thread, let it clean up on its own when done */
     SDL_DetachThread(initMidiThread);
