--- src/snipe2d.cpp.orig	Thu Oct 19 00:35:42 2006
+++ src/snipe2d.cpp	Sun Sep 30 21:41:40 2007
@@ -800,7 +800,7 @@
 {
   if (Game.GameState != OESGAME_PLAY) return 0;
   sniperbgm_release(Game.BGM);
-  oes_audio_close();
+  //oes_audio_close();
   SDL_WM_GrabInput(SDL_GRAB_OFF);
   SDL_ShowCursor(1);
   Game.GameState = OESGAME_PAUSED;
@@ -817,7 +817,7 @@
       SDL_ShowCursor(0);
       SDL_WM_GrabInput(SDL_GRAB_ON);
     }
-  oes_audio_open();
+  //oes_audio_open();
   sniperbgm_grab(Game.BGM);
   Game.GameState = OESGAME_UNPAUSED;
   return 0;
