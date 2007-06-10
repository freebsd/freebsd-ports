--- u_error.h.orig	Tue Jul 26 09:40:00 2005
+++ u_error.h
@@ -15,6 +15,6 @@
  *
  */
 
-extern void	X_error_handler(Display *d, XErrorEvent *err_ev);
+extern int	X_error_handler(Display *d, XErrorEvent *err_ev);
 extern void	error_handler(int err_sig);
 extern void	my_quit(Widget w, XEvent *event, String *params, Cardinal *num_params);
