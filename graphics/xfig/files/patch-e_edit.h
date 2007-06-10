--- e_edit.h.orig	Tue Jul 26 09:39:58 2005
+++ e_edit.h
@@ -24,7 +24,7 @@
 extern void	paste_panel_key(Widget w, XKeyEvent *event);
 extern Widget	color_selection_panel(char *label, char *wname, char *name, Widget parent, Widget below, Widget beside, Widget *button, Widget *popup, int color, XtCallbackProc callback);
 extern void	color_select(Widget w, Color color);
-extern void edit_item (F_line *p, int type, int x, int y);
+extern void edit_item (void *p, int type, int x, int y);
 extern void edit_item_selected (void);
 extern void push_apply_button (void);
 
