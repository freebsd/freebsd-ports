--- tong.cpp.orig	2012-10-31 18:18:19.000000000 +0100
+++ tong.cpp	2012-11-15 13:27:09.000000000 +0100
@@ -63,6 +63,7 @@
 #define SCREEN_CREDITS      8
 
 #define DEMO_TIME           8000
+#define MIN_TIME            45
 
 #define GP2X_BUTTON_UP         0
 #define GP2X_BUTTON_UPLEFT     1
@@ -1854,6 +1855,13 @@
 		SDL_Flip(screen);
 		lastlastupdate=lastupdate;
 		lastupdate=SDL_GetTicks();
+
+		// limit to 1000/MIN_TIME fps
+		if (lastupdate-lastlastupdate < MIN_TIME) {
+		    SDL_Delay(MIN_TIME - (lastupdate - lastlastupdate));
+		}
+		lastupdate = SDL_GetTicks();
+		
 	}  //main game loop
 
 	Mix_FreeMusic(music);
