--- src/support/widgets/gtkmplayer.c.orig	Sat Apr  5 18:54:40 2003
+++ src/support/widgets/gtkmplayer.c	Sat Apr  5 18:55:27 2003
@@ -30,6 +30,7 @@
 #include <errno.h>
 #include <ctype.h>
 #include <math.h>
+#include <signal.h>
 
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
