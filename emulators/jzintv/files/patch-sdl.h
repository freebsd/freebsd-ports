--- src/sdl.h.orig	2006-07-06 10:11:46.000000000 +0800
+++ src/sdl.h	2008-04-06 21:15:05.000000000 +0800
@@ -2,15 +2,6 @@
 /*  Wrapper around "#include <SDL / *>" to handle BSD's oddness.            */
 /* ======================================================================== */
 
-#ifdef __FreeBSD__
-# define SDL_H_ 1
-# include <SDL11/SDL.h>
-# include <SDL11/SDL_audio.h>
-# include <SDL11/SDL_events.h>
-# include <SDL11/SDL_error.h>
-# include <SDL11/SDL_thread.h>
-#endif
-
 #ifndef SDL_H_ 
 # define SDL_H_ 1
 # include <SDL/SDL.h>
