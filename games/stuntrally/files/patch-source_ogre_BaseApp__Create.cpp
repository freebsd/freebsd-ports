--- source/ogre/BaseApp_Create.cpp.orig	2015-09-18 09:21:11 UTC
+++ source/ogre/BaseApp_Create.cpp
@@ -254,7 +254,7 @@ bool BaseApp::configure()
 
 	mRoot->initialise(false);
 
-	Uint32 flags = SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_HAPTIC|SDL_INIT_NOPARACHUTE;
+	Uint32 flags = SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_NOPARACHUTE;
 	if (SDL_WasInit(flags) == 0)
 	{
 		SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
