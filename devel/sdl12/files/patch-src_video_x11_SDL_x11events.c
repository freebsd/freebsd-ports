

Patch attached with submission follows:

--- src/video/x11/SDL_x11events.c.orig	2010-08-29 20:13:12.455316094 +0300
+++ src/video/x11/SDL_x11events.c	2010-08-29 20:14:46.875763077 +0300
@@ -441,8 +441,10 @@
 if ( xevent.xcrossing.mode == NotifyUngrab )
 printf("Mode: NotifyUngrab\n");
 #endif
-		if ( xevent.xcrossing.detail != NotifyInferior ) {
-			if ( this->input_grab == SDL_GRAB_OFF ) {
+		if ( (xevent.xcrossing.mode != NotifyGrab) &&
+		     (xevent.xcrossing.mode != NotifyUngrab) &&
+		     (xevent.xcrossing.detail != NotifyInferior) ) {
+              		if ( this->input_grab == SDL_GRAB_OFF ) {
 				posted = SDL_PrivateAppActive(0, SDL_APPMOUSEFOCUS);
 			} else {
 				posted = SDL_PrivateMouseMotion(0, 0,


