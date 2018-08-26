--- src/YOGClientLobbyScreen.cpp.orig	2018-08-26 04:08:24 UTC
+++ src/YOGClientLobbyScreen.cpp
@@ -326,7 +326,7 @@ void YOGClientLobbyScreen::playerListUpdated()
 
 void YOGClientLobbyScreen::hostGame()
 {
-	ChooseMapScreen cms("maps", "map", false, "games", "game", false);
+	ChooseMapScreen cms("maps", "map", false, "games", "game", NULL);
 	int rc = cms.execute(globalContainer->gfx, 40);
 	if(rc == ChooseMapScreen::OK)
 	{
