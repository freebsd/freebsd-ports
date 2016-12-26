Don't crash with empty Paks/ directory.

--- sdl/menu.c.orig	2015-04-18 21:21:56 UTC
+++ sdl/menu.c
@@ -747,7 +747,7 @@ void Menu()
 		}
 		freeAllLogs();
 		termMenu();
-		if(ctrl == 2)
+		if(dListTotal == 0 || ctrl == 2)
 		{
 			if (filelist)
 			{
