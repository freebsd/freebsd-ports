
$FreeBSD$

--- sound.c.orig	Mon Apr  3 23:42:42 2000
+++ sound.c	Sat Sep 22 22:18:55 2001
@@ -172,6 +172,9 @@
 	if (!wave_device_available)
 		soundlevdoneflag=FALSE;
 #endif
+#if defined _SDL || defined _SDL_SOUND
+    SDL_Delay(10);	/* Let some CPU time go away */
+#endif
 #ifdef ARM
     gretrace();
     soundint();
