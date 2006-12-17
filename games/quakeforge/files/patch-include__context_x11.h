--- ./include/context_x11.h.orig	Sun Mar 21 02:39:59 2004
+++ ./include/context_x11.h	Sun Dec 17 16:04:17 2006
@@ -51,12 +51,10 @@
 extern Window	x_root;
 extern Window	x_win;
 extern XVisualInfo *x_visinfo;
-extern vec3_t	x_gamma;
 extern int		x_screen;
 extern int		x_shmeventtype;
 extern Time		x_time;
 extern Time		x_mouse_time;
-extern qboolean doShm;
 extern qboolean oktodraw;
 extern qboolean x_have_focus;
 
