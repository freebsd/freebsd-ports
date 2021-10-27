--- SpaceCadetPinball/winmain.cpp.orig	2021-10-14 18:28:42 UTC
+++ SpaceCadetPinball/winmain.cpp
@@ -56,7 +56,7 @@ int winmain::WinMain(LPCSTR lpCmdLine)
 		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Could not initialize SDL2", SDL_GetError(), nullptr);
 		return 1;
 	}
-	BasePath = SDL_GetBasePath();
+	BasePath = SDL_strdup("./");
 
 	pinball::quickFlag = strstr(lpCmdLine, "-quick") != nullptr;
 	DatFileName = options::get_string("Pinball Data", pinball::get_rc_string(168, 0));
