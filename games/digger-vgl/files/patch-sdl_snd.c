
$FreeBSD$

--- sdl_snd.c	2001/09/22 19:20:28	1.1
+++ sdl_snd.c	2001/09/22 19:20:38
@@ -15,7 +15,6 @@
 
 bool initsounddevice(void)
 {
-//	SDL_PauseAudio(0);
 	return(TRUE);
 }
 
