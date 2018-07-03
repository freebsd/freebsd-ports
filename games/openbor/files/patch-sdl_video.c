Haptic isn't implemented on BSDs thus disabled by default

--- sdl/video.c.orig	2018-07-02 13:46:53 UTC
+++ sdl/video.c
@@ -46,7 +46,11 @@ int brightness = 0;
 void initSDL()
 {
 	SDL_DisplayMode video_info;
-	int init_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC;
+	int init_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK;
+
+#ifndef SDL_HAPTIC_DISABLED
+	init_flags |= SDL_INIT_HAPTIC;
+#endif
 
     /*#if EE_CURRENT_PLATFORM == EE_PLATFORM_WINDOWS
        SDL_setenv("SDL_AUDIODRIVER", "directsound", true);
