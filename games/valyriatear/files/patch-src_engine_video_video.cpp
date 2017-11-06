--- src/engine/video/video.cpp.orig	2016-04-25 20:52:18 UTC
+++ src/engine/video/video.cpp
@@ -434,7 +434,7 @@ bool VideoEngine::ApplySettings()
     SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
     SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
 
-    if(SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == false) {
+    if(SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == NULL) {
         // RGB values of 1 for each and 8 for depth seemed to be sufficient.
         // 565 and 16 here because it works with them on this computer.
         // NOTE from prophile: this ought to be changed to 5558
@@ -447,7 +447,7 @@ bool VideoEngine::ApplySettings()
         SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 0);
         SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
 
-        if(SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == false) {
+        if(SDL_SetVideoMode(_temp_width, _temp_height, 0, flags) == NULL) {
             IF_PRINT_WARNING(VIDEO_DEBUG) << "SDL_SetVideoMode() failed with error: " << SDL_GetError() << std::endl;
 
             _temp_fullscreen = _fullscreen;
