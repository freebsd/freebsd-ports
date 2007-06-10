--- w_print.c.orig	Tue Jul 26 09:40:01 2005
+++ w_print.c
@@ -100,7 +100,7 @@
         "<Message>WM_PROTOCOLS: DismissPrint()\n";
 static void     print_panel_dismiss(Widget w, XButtonEvent *ev), do_clear_batch(Widget w);
 static void	get_magnif(void);
-static void update_mag(Widget widget, XtPointer *item, XtPointer *event);
+static void update_mag(Widget widget, XtPointer item, XtPointer event);
 void		do_print(Widget w), do_print_batch(Widget w);
 static XtCallbackProc switch_print_layers(Widget w, XtPointer closure, XtPointer call_data);
 
@@ -263,7 +263,7 @@
 /* as the user types in a magnification, update the figure size */
 
 static void
-update_mag(Widget widget, XtPointer *item, XtPointer *event)
+update_mag(Widget widget, XtPointer item, XtPointer event)
 {
     char	   *buf;
 
