--- src/Functions.cpp.orig	2018-10-07 15:06:26 UTC
+++ src/Functions.cpp
@@ -416,7 +416,7 @@ void onVideoResize(ImageManager& imageMa
 
 ScreenData init(){
 	//Initialze SDL.
-	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) {
+	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER)==-1) {
         std::cerr << "FATAL ERROR: SDL_Init failed\nError: " << SDL_GetError() << std::endl;
         return creationFailed();
 	}
