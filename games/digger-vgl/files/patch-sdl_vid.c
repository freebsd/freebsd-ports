
$FreeBSD$

--- sdl_vid.c.orig	Mon Apr  3 23:42:42 2000
+++ sdl_vid.c	Thu Sep 13 01:24:35 2001
@@ -1,5 +1,18 @@
-#include <stdlib.h>
+/*
+ * ---------------------------------------------------------------------------
+ * "THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp): Maxim
+ * Sobolev <sobomax@altavista.net> wrote this file. As long as you retain
+ * this  notice you can  do whatever you  want with this stuff. If we meet
+ * some day, and you think this stuff is worth it, you can buy me a beer in
+ * return.
+ * 
+ * Maxim Sobolev
+ * --------------------------------------------------------------------------- 
+ */
 
+/* malloc() and friends */
+#include <stdlib.h>
+/* Lovely SDL */
 #include <SDL.h>
 
 #include "def.h"
@@ -48,8 +61,11 @@
 SDL_Color *ipalettes[] = {vga16_pal1i, vga16_pal2i};
 Sint4	currpal=0;
 
+Uint32	addflag=0;
+
 SDL_Surface *screen = NULL;
 
+/* Data structure holding pending updates */
 struct PendNode {
 	void *prevnode;
 	void *nextnode;
@@ -77,6 +93,46 @@
 {
 }
 
+bool setmode(void)
+{
+	if((screen = SDL_SetVideoMode(640, 400, 8, \
+	    SDL_HWSURFACE | SDL_HWPALETTE | addflag)) == NULL)
+		return(FALSE);
+	else
+		return(TRUE);
+}
+
+void switchmode(void)
+{
+	Uint32 saved;
+	SDL_Surface *tmp = NULL;
+	SDL_Surface *oldscreen;
+	
+	vgageti(0, 0, (Uint3 *)&tmp, 80, 200);
+	oldscreen = screen;
+	saved = addflag;
+
+	if(addflag == 0)
+		addflag = SDL_FULLSCREEN;
+	else
+		addflag = 0;
+	if(setmode() == FALSE) {
+		addflag = saved;
+		if(setmode() == FALSE) {
+			fprintf(stderr, "Fatal: failed to change videomode and"\
+				"fallback mode failed as well. Exitting.\n");
+			exit(1);
+		}
+	}
+
+	SDL_SetColors(screen, tmp->format->palette->colors, 0, \
+		tmp->format->palette->ncolors);
+	vgaputi(0, 0, (Uint3 *)&tmp, 80, 200);
+	SDL_FreeSurface(tmp);
+	SDL_FreeSurface(oldscreen);
+}
+
+
 void vgainit(void)
 {
 	SDL_Surface *tmp = NULL;
@@ -92,7 +148,7 @@
 	}
 	SDL_WM_SetCaption("D I G G E R", NULL);
 	SDL_WM_SetIcon(tmp, NULL);
-	if ((screen = SDL_SetVideoMode(640, 400, 8, SDL_HWSURFACE | SDL_HWPALETTE)) == NULL) {
+	if(setmode() == FALSE) {
 		fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n", SDL_GetError());
 		exit(1);
         }
@@ -131,7 +187,6 @@
 {
 	struct PendNode *p;
 
-	SDL_UnlockSurface(screen);				
 	for(p=First;p!=NULL;)
 	{
 		SDL_UpdateRect(screen,p->rect.x,p->rect.y,p->rect.w,p->rect.h);
@@ -139,7 +194,6 @@
 		free(p);
 		p = First;
 	}
-	SDL_LockSurface(screen);
 	pendnum = 0;
 }
 
@@ -161,12 +215,26 @@
 	tmp->format->palette = screen->format->palette;
 	SDL_BlitSurface(tmp, NULL, screen, &new->rect);
 	tmp->format->palette = reserv;
+/* 
+ * Following piece of code comparing already pending updates with current with
+ * main goal to prevent redrawing overlapping rectangles several times.
+ */ 
 	
 	for(ptr=First;ptr!=NULL;ptr=ptr->nextnode) {
 		if((new->rect.x >= ptr->rect.x) &&
 		   (new->rect.y >= ptr->rect.y) &&
-		   ((new->rect.x+new->rect.w)<=(ptr->rect.x+ptr->rect.w)) &&
-		   ((new->rect.y+new->rect.h)<=(ptr->rect.y+ptr->rect.h))) {
+		   ((new->rect.x+new->rect.w) <= (ptr->rect.x+ptr->rect.w)) &&
+		   ((new->rect.y+new->rect.h) <= (ptr->rect.y+ptr->rect.h))) {
+			free(new);
+			return;
+		} else if((new->rect.x <= ptr->rect.x) &&
+		   (new->rect.y <= ptr->rect.y) &&
+		   ((new->rect.x+new->rect.w) >= (ptr->rect.x+ptr->rect.w)) &&
+		   ((new->rect.y+new->rect.h) >= (ptr->rect.y+ptr->rect.h))) {
+			ptr->rect.x = new->rect.x;
+			ptr->rect.y = new->rect.y;
+			ptr->rect.w = new->rect.w;
+			ptr->rect.h = new->rect.h;
 			free(new);
 			return;
 		}
@@ -211,6 +279,9 @@
 	Sint4 rval = 0;
 	Uint8 *pixels;
 
+	if ((x > 319) || (y > 199))
+	       return (0xff);
+
 	vgageti(x, y, (Uint3 *)&tmp, 1, 1);
 	pixels = (Uint8 *)tmp->pixels;
 	for (yi=0;yi<tmp->h;yi++)
@@ -260,6 +331,8 @@
 	Sint4 w=3, h=12, size;
 	Sint4 i;
 
+	if(((ch - 32) >= 0x5f) || (ch < 32))
+		return;
 	tmp = ch2bmap(alphas[ch-32], w, h);
 	size = tmp->w*tmp->h;
 	copy = malloc(size);
