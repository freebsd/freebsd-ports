--- src/game/loadmap.cpp.orig	2008-01-30 22:37:44 UTC
+++ src/game/loadmap.cpp
@@ -63,7 +63,7 @@ std::ostringstream	TempString;
         throw LoadMapError();
     }
 
-	if (missionData.player != '\0')
+	if (missionData.player != nullptr)
 		printf ("%s line %i: Player = %s\n", __FILE__, __LINE__, missionData.player);
 
 	if (gamemode == GAME_MODE_SINGLE_PLAYER){
