
$FreeBSD$

--- ncurses/_panel_wrap.c	2001/03/13 17:00:02	1.1
+++ ncurses/_panel_wrap.c	2001/03/13 17:00:26
@@ -588,8 +588,8 @@
 extern PANEL *new_panel(WINDOW *);
 extern PANEL *panel_above(const PANEL *);
 extern PANEL *panel_below(const PANEL *);
-extern int set_panel_userptr(PANEL *,const void *);
-extern const void *panel_userptr(const PANEL *);
+/*extern int set_panel_userptr(PANEL *,const void *);*/
+/*extern const void *panel_userptr(const PANEL *);*/
 extern int move_panel(PANEL *,int ,int );
 extern int replace_panel(PANEL *,WINDOW *);
 extern int panel_hidden(const PANEL *);
