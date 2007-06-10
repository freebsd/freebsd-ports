--- e_edit.c.orig	Tue Oct 10 16:57:20 2006
+++ e_edit.c
@@ -603,7 +603,7 @@
 	}
 }
 
-void	edit_item(F_line *p, int type, int x, int y);
+void	edit_item(void *p, int type, int x, int y);
 void	edit_spline_point(F_spline *spline, int type, int x, int y, F_point *previous_point, F_point *the_point);
 void	edit_figure_comments(int x, int y, unsigned int shift);
 
@@ -738,7 +738,7 @@
 	XtDestroyWidget(comment_popup);
 }
 
-void edit_item(F_line *p, int type, int x, int y)
+void edit_item(void *p, int type, int x, int y)
 {
     XtWidgetGeometry xtgeom,comp;
     int		    llx, lly, urx, ury, dum;
@@ -3963,7 +3963,7 @@
 
 static XtCallbackRec f_sel_callback[] =
 {
-    {f_menu_popup, NULL},
+    {(XtCallbackProc)f_menu_popup, NULL},
     {NULL, NULL},
 };
 
