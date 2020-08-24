--- display.c.orig	2009-01-17 20:11:47 UTC
+++ display.c
@@ -30,6 +30,8 @@
 #include <gtkdatabox_marker.h>
 
 extern GtkWidget *databox;
+extern GtkWidget *menubar;
+GtkWidget *glade_window;
 
 #define DEBUG 0
 
@@ -38,7 +40,6 @@ void	init_widgets();
 void	fix_widgets();
 
 int	triggered = 0;		/* whether we've triggered or not */
-void	*font;
 int	math_warning = 0;	/* TRUE if math has a problem */
 
 struct signal_stats stats;
