--- w_fontpanel.c.orig	Fri Feb 24 12:23:06 2006
+++ w_fontpanel.c
@@ -143,7 +143,7 @@
 	ps_fontmenu_items[i].type = MENU_IMAGESTRING;		/* put the fontnames in
 								 * menu */
 	ps_fontmenu_items[i].label = ps_fontinfo[i].name;
-	ps_fontmenu_items[i].info = (caddr_t) (i - 1);		/* index for font # */
+	ps_fontmenu_items[i].info = (caddr_t) i;		/* index for font # */
     }
 
     for (i = 0; i < NUM_LATEX_FONTS; i++) {
@@ -359,7 +359,7 @@
     char	   *font_name = mi->label;
 
     if (*flag_sel)
-	*font_ps_sel = (int) mi->info;	/* set ps font to one selected */
+	*font_ps_sel = (int) mi->info - 1;	/* set ps font to one selected */
     else
 	*font_latex_sel = (int) mi->info;	/* set latex font to one
 						 * selected */
