--- src/burner/sdl/drv.cpp.orig	2024-11-21 06:47:25 UTC
+++ src/burner/sdl/drv.cpp
@@ -3,7 +3,7 @@ int bDrvOkay = 0;                       // 1 if the Dr
 #include "neocdlist.h"
 int bDrvOkay = 0;                       // 1 if the Driver has been initted okay, and it's okay to use the BurnDrv functions
 
-char szAppRomPaths[DIRS_MAX][MAX_PATH] = { { "/usr/local/share/roms/" }, { "roms/" }, };
+char szAppRomPaths[DIRS_MAX][MAX_PATH] = { { "/usr/local/share/fbneo/roms/" }, { "roms/" }, };
 
 static bool bSaveRAM = false;
 
