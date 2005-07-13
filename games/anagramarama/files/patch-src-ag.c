--- src/ag.c.orig	Wed Jul 13 15:52:56 2005
+++ src/ag.c	Wed Jul 13 15:54:22 2005
@@ -1723,6 +1723,12 @@
 SDL_Surface *screen;
 struct sprite* letters = NULL;
 //pthread_t audio;
+	// buffer sounds
+	int audio_rate = MIX_DEFAULT_FREQUENCY;
+	Uint16 audio_format = AUDIO_S16;
+	int audio_channels = 1;
+	int audio_buffers = 256;
+
 
 	// seed the random generator
 	srand(time(NULL));
@@ -1742,12 +1748,6 @@
 	}
 
 	SDL_WM_SetCaption("Anagramarama", "ANAGRAMARAMA");
-
-	// buffer sounds
-	int audio_rate = MIX_DEFAULT_FREQUENCY;
-	Uint16 audio_format = AUDIO_S16;
-	int audio_channels = 1;
-	int audio_buffers = 256;
 
 	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)){
 		printf("unable to open audio!\n");
