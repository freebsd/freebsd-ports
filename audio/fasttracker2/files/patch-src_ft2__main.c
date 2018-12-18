--- src/ft2_main.c.orig	2018-12-18 11:08:11 UTC
+++ src/ft2_main.c
@@ -190,6 +190,7 @@ int main(int argc, char *argv[])
 
     //benchmarkAudioChannelMixer(); /* for development testing */
 
+#ifndef __FreeBSD__
     /* set up MIDI input (in a thread because it can take quite a while on f.ex. macOS) */
     initMidiThread = SDL_CreateThread(initMidiFunc, "FT2 Clone MIDI Initialization Thread", NULL);
     if (initMidiThread == NULL)
@@ -199,6 +200,7 @@ int main(int argc, char *argv[])
         return (1);
     }
     SDL_DetachThread(initMidiThread); /* don't wait for this thread, let it clean up when done */
+#endif
 
     setupWaitVBL();
     while (editor.programRunning)
