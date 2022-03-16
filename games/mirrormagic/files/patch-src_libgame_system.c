Forcibly pump events, otherwise the game stops receiving events
shortly after the start

--- src/libgame/system.c.orig	2018-04-10 19:44:08 UTC
+++ src/libgame/system.c
@@ -1579,6 +1579,7 @@ void SetAudioMode(boolean enabled)
 
 boolean PendingEvent(void)
 {
+  SDL_PumpEvents();
   return (SDL_PollEvent(NULL) ? TRUE : FALSE);
 }
 
