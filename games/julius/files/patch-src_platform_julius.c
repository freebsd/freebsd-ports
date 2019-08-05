--- src/platform/julius.c.orig	2019-08-03 16:50:03 UTC
+++ src/platform/julius.c
@@ -369,7 +369,8 @@ static int init_sdl(void)
         return 0;
     }
 #if SDL_VERSION_ATLEAST(2, 0, 4)
-    SDL_SetHint(SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH, "1");
+    SDL_SetHint(SDL_HINT_MOUSE_TOUCH_EVENTS, "0");
+    SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "0");
 #endif
     SDL_Log("SDL initialized");
     return 1;
