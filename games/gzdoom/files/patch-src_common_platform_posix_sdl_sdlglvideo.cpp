--- src/common/platform/posix/sdl/sdlglvideo.cpp.orig	2021-10-20 06:18:37 UTC
+++ src/common/platform/posix/sdl/sdlglvideo.cpp
@@ -396,9 +396,7 @@ SDLVideo::SDLVideo ()
 	}
 
 	// Fail gracefully if we somehow reach here after linking against a SDL2 library older than 2.0.6.
-	SDL_version sdlver;
-	SDL_GetVersion(&sdlver);
-	if (!(sdlver.patch >= 6))
+	if (!SDL_VERSION_ATLEAST(2, 0, 6))
 	{
 		I_FatalError("Only SDL 2.0.6 or later is supported.");
 	}
