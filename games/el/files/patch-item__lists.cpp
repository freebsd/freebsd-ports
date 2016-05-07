--- item_lists.cpp.orig	2014-01-06 13:53:40 UTC
+++ item_lists.cpp
@@ -796,7 +796,7 @@ namespace ItemLists
 	{
 		if (!last_mod_time)
 			return;
-		if (force || (last_mod_time && abs(last_mod_time - SDL_GetTicks()) > 5000))
+		if (force || (last_mod_time && abs((Sint32)(last_mod_time - SDL_GetTicks())) > 5000))
 			save();
 	}
 
