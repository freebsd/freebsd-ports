--- src/ft2_main.c.orig	2019-03-19 07:15:21 UTC
+++ src/ft2_main.c
@@ -188,6 +188,7 @@ int main(int argc, char *argv[])
 
 	//benchmarkAudioChannelMixer(); // for development testing
 
+#ifndef __FreeBSD__
 	// set up MIDI input (in a thread because it can take quite a while on f.ex. macOS)
 	initMidiThread = SDL_CreateThread(initMidiFunc, NULL, NULL);
 	if (initMidiThread == NULL)
@@ -197,6 +198,7 @@ int main(int argc, char *argv[])
 		return (1);
 	}
 	SDL_DetachThread(initMidiThread); // don't wait for this thread, let it clean up when done
+#endif
 
 	SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
 
