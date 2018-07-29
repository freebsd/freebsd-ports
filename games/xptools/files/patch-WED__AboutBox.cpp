--- src/WEDWindows/WED_AboutBox.cpp.orig	2018-07-08 15:08:31 UTC
+++ src/WEDWindows/WED_AboutBox.cpp
@@ -79,8 +79,7 @@ void		WED_AboutBox::Draw(GUI_GraphState 
 	}
 
 	char buf[1024];
-
-	sprintf(buf,"WorldEditor " WED_VERSION_STRING ", compiled on "__DATE__" "__TIME__);
+	 sprintf( buf, "WorldEditor " WED_VERSION_STRING ", compiled on " "%s %s", __DATE__, __TIME__);
 
 	GUI_FontDrawScaled(state, font_UI_Basic, color,
 		bounds[0],
