--- src/gui.cpp.orig	2011-05-06 09:46:43 UTC
+++ src/gui.cpp
@@ -117,7 +117,7 @@ void ico_button::draw(int active, image 
 
 }
 
-extern long S_BUTTON_PRESS_SND;
+extern int S_BUTTON_PRESS_SND;
 extern int sfx_volume;
 
 void ico_button::handle_event(event &ev, image *screen, InputManager *im)
