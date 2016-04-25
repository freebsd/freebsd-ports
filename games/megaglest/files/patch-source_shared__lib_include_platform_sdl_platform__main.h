--- source/shared_lib/include/platform/sdl/platform_main.h.orig	2016-04-02 12:37:33 UTC
+++ source/shared_lib/include/platform/sdl/platform_main.h
@@ -667,7 +667,7 @@ int mainSetup(int argc, char **argv) {
 	}
 	else {
 		 if(SystemFlags::VERBOSE_MODE_ENABLED) printf("In [%s::%s Line: %d]\n",__FILE__,__FUNCTION__,__LINE__);
-		 if(SDL_Init(SDL_INIT_EVERYTHING) < 0)  {
+		 if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) < 0)  {
 			if(SystemFlags::VERBOSE_MODE_ENABLED) printf("In [%s::%s Line: %d]\n",__FILE__,__FUNCTION__,__LINE__);
 			std::cerr << "Couldn't initialize SDL: " << SDL_GetError() << "\n";
 			return 3;
