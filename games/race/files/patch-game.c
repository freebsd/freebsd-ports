--- src/game.c.orig	Tue Jul 16 23:47:16 2002
+++ src/game.c	Tue Jul 16 23:48:22 2002
@@ -39,7 +39,7 @@
   player.z   	= -1000;
 
   debugf("Reset Player Variables");
-  playmusic("data/music/fuck.xm");
+  playmusic("%%DATADIR%%/data/music/fuck.xm");
   newgame = 0;
   timestart = SDL_GetTicks();
   printf("\nLoaded Map:\n  %s (data/%s)\n  %s\n\n",
