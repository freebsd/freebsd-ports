Don't crash with empty Paks/ directory.

--- sdl/menu.c.orig	2018-07-06 15:13:16 UTC
+++ sdl/menu.c
@@ -753,7 +753,7 @@ void Menu()
 		}
 		freeAllLogs();
 		termMenu();
-		if(ctrl == 2)
+		if(dListTotal == 0 || ctrl == 2)
 		{
 			if (filelist)
 			{
