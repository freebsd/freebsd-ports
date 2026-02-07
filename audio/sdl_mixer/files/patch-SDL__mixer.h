--- SDL_mixer.h.orig	2012-01-15 22:01:04 UTC
+++ SDL_mixer.h
@@ -621,6 +621,8 @@ extern DECLSPEC Mix_Chunk * SDLCALL Mix_
 /* Close the mixer, halting all playing audio */
 extern DECLSPEC void SDLCALL Mix_CloseAudio(void);
 
+extern DECLSPEC int Mix_GetMixerInfo(SDL_AudioSpec *, char *, int);
+
 /* We'll use SDL for reporting errors */
 #define Mix_SetError	SDL_SetError
 #define Mix_GetError	SDL_GetError
