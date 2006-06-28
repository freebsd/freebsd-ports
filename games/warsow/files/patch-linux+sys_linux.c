--- linux/sys_linux.c.orig	Thu May 11 22:18:54 2006
+++ linux/sys_linux.c	Thu Jun  1 15:44:44 2006
@@ -434,7 +392,7 @@
 			APIfunc = GetGameAPI;
 #endif
 			lib = &game_library;
-			libname = "game_" ARCH ".so";
+			libname = "game.so";
 			apifuncname = "GetGameAPI";
 			break;
 		}
@@ -445,7 +403,7 @@
 			APIfunc = GetCGameAPI;
 #endif
 			lib = &cgame_library;
-			libname = "cgame_" ARCH ".so";
+			libname = "cgame.so";
 			apifuncname = "GetCGameAPI";
 			break;
 		}
@@ -456,7 +414,7 @@
 			APIfunc = GetUIAPI;
 #endif
 			lib = &ui_library;
-			libname = "ui_" ARCH ".so";
+			libname = "ui.so";
 			apifuncname = "GetUIAPI";
 			break;
 		}
