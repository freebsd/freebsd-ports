--- src/engine/video/video.cpp.orig	2010-05-16 23:38:27 UTC
+++ src/engine/video/video.cpp
@@ -470,7 +470,7 @@ bool VideoEngine::ApplySettings() {
 		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
 		SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
 
-		if (SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == false) {
+		if (SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == nullptr) {
 			// RGB values of 1 for each and 8 for depth seemed to be sufficient.
 			// 565 and 16 here because it works with them on this computer.
 			// NOTE from prophile: this ought to be changed to 5558
@@ -483,7 +483,7 @@ bool VideoEngine::ApplySettings() {
 			SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 0);
 			SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
 
-			if (SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == false) {
+			if (SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == nullptr) {
 				IF_PRINT_WARNING(VIDEO_DEBUG) << "SDL_SetVideoMode() failed with error: " << SDL_GetError() << endl;
 
 				_temp_fullscreen = _fullscreen;
