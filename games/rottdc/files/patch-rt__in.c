--- rt_in.c.orig	Wed Feb 18 08:30:12 2004
+++ rt_in.c	Wed Feb 18 08:54:20 2004
@@ -665,14 +665,16 @@
 
    {
    int buttons = 0;
+#if USE_SDL
+   int bmask, i;
+   const static int tbl[] = {SDL_BUTTON_LEFT,SDL_BUTTON_RIGHT,SDL_BUTTON_MIDDLE,SDL_BUTTON_WHEELUP,SDL_BUTTON_WHEELDOWN};
+#endif
 
    IN_PumpEvents();
 
 #if USE_SDL
 #if 1
-	int bmask = SDL_GetMouseState(NULL,NULL);
-	int i;
-	const static int tbl[] = {SDL_BUTTON_LEFT,SDL_BUTTON_RIGHT,SDL_BUTTON_MIDDLE,SDL_BUTTON_WHEELUP,SDL_BUTTON_WHEELDOWN};
+	bmask = SDL_GetMouseState(NULL,NULL);
 	for(i=0;i<sizeof(tbl);i++) {
 		if (bmask & SDL_BUTTON(tbl[i])) buttons|=1<<i;
 	}
