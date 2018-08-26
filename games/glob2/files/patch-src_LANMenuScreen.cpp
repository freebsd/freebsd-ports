--- src/LANMenuScreen.cpp.orig	2018-08-26 04:11:03 UTC
+++ src/LANMenuScreen.cpp
@@ -62,7 +62,7 @@ void LANMenuScreen::onAction(Widget *source, Action ac
 		}
 		else if(par1 == HOST)
 		{
-			ChooseMapScreen cms("maps", "map", false, "games", "game", false);
+			ChooseMapScreen cms("maps", "map", false, "games", "game", NULL);
 			int rc = cms.execute(globalContainer->gfx, 40);
 			if(rc == ChooseMapScreen::OK)
 			{
