--- src/wl_iwad_picker.cpp.orig	2018-08-17 16:43:51 UTC
+++ src/wl_iwad_picker.cpp
@@ -1,6 +1,7 @@
 // From ZDoom!
 
 #include <algorithm>
+#include <sys/wait.h>
 
 #include "zdoomsupport.h"
 
@@ -227,7 +228,7 @@ int I_PickIWad (WadStuff *wads, int numwads, bool show
 	const char *str;
 	if((str=getenv("KDE_FULL_SESSION")) && strcmp(str, "true") == 0)
 	{
-		FString cmd("kdialog --title \""GAMESIG" "DOTVERSIONSTR": Select an IWAD to use\""
+		FString cmd("kdialog --title \"" GAMESIG " " DOTVERSIONSTR ": Select an IWAD to use\""
 		            " --menu \"" GAMENAME " found more than one IWAD\n"
 		            "Select from the list below to determine which one to use:\"");
 
