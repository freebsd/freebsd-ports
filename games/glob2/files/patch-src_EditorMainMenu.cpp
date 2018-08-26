--- src/EditorMainMenu.cpp.orig	2018-08-26 04:04:18 UTC
+++ src/EditorMainMenu.cpp
@@ -90,7 +90,7 @@ void EditorMainMenu::onAction(Widget *source, Action a
 		}
 		else if (par1==LOADMAP)
 		{
-			ChooseMapScreen chooseMapScreen("maps", "map", false, "games", "game", false);
+			ChooseMapScreen chooseMapScreen("maps", "map", false, "games", "game", NULL);
 			int rc=chooseMapScreen.execute(globalContainer->gfx, 40);
 			if (rc==ChooseMapScreen::OK)
 			{
