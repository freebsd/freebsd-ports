--- icon_window.cpp.orig	2014-01-06 13:53:40 UTC
+++ icon_window.cpp
@@ -358,7 +358,7 @@ namespace IconWindow
 		size_t index = (has_highlight)? 1: 0;
 		if (flashing)
 		{
-			if (abs(SDL_GetTicks() - last_flash_change) > 250)
+			if (abs((Sint32)(SDL_GetTicks() - last_flash_change)) > 250)
 			{
 				last_flash_change = SDL_GetTicks();
 				flashing--;
