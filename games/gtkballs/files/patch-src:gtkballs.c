$FreeBSD$

--- src/gtkballs.c.orig	Wed Oct 10 01:11:10 2001
+++ src/gtkballs.c	Thu Oct 11 04:20:16 2001
@@ -471,6 +471,7 @@
         }
   	new_turn(5);
 
+	setregid(getegid(), -1);
   	gtk_init(&argc, &argv);
 
   	main_window=gtk_widget_new(gtk_window_get_type(),
