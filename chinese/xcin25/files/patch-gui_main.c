--- src/gui_main.c.orig	Mon Nov 26 08:54:25 2001
+++ src/gui_main.c	Tue Apr  9 19:15:32 2002
@@ -234,7 +234,7 @@
 /*
 	len = wch_mblen(tmp);
 */
-	len = 4;
+	len = (tmp->s[1] != '\0') ? 2 : 1;
         XmbDrawImageString(gui->display, win->window,
             win->font->fontset, win->wingc[GCM_idx], x, y, (char *)tmp->s, len);
 	x += XmbTextEscapement(win->font->fontset, (char *)tmp->s, len);
