--- src/ft2_main.c.orig	2018-11-27 19:40:20 UTC
+++ src/ft2_main.c
@@ -187,15 +187,6 @@ int main(int argc, char *argv[])
         enterFullscreen();
     }
 
-    //benchmarkAudioChannelMixer(); /* for development testing */
-
-    /* set up MIDI input (in a thread because it can take quite a while on f.ex. macOS) */
-    initMidiThread = SDL_CreateThread(initMidiFunc, "FT2 Clone MIDI Initialization Thread", NULL);
-    if (initMidiThread == NULL)
-    {
-        cleanUpAndExit();
-        return (1);
-    }
     SDL_DetachThread(initMidiThread); /* don't wait for this thread, let it clean up when done */
 
     setupWaitVBL();
