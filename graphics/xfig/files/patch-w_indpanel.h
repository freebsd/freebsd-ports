--- w_indpanel.h.orig	Tue Jul 26 09:40:01 2005
+++ w_indpanel.h
@@ -164,7 +164,7 @@
 extern void	show_depth(ind_sw_info *sw), show_zoom(ind_sw_info *sw);
 extern void	show_fillstyle(ind_sw_info *sw);
 extern void	fontpane_popup(int *psfont_adr, int *latexfont_adr, int *psflag_adr, void (*showfont_fn) (/* ??? */), Widget show_widget);
-extern void	make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap **images, char **texts, Widget parent, XtCallbackProc callback);
+extern void	make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap *images, char **texts, Widget parent, XtCallbackProc callback);
 extern void	tog_selective_update(long unsigned int mask);
 extern unsigned long cur_indmask;	/* mask showing which indicator buttons are mapped */
 extern void	inc_zoom(ind_sw_info *sw), dec_zoom(ind_sw_info *sw), fit_zoom(ind_sw_info *sw);
