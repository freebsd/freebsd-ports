--- src/widgets/gtkcolorbutton.c.orig	Wed Jul  3 19:47:16 2002
+++ src/widgets/gtkcolorbutton.c	Tue Oct 26 17:04:03 2004
@@ -25,11 +25,11 @@
 #undef GTK_DISABLE_DEPRECATED
 #warning GTK_DISABLE_DEPRECATED
 
+#include "gtkcolorbutton.h"
+
 #include "giram.h"
 
 #include "giramintl.h"
-
-#include "gtkcolorbutton.h"
 
 static void  gtk_color_button_destroy(GtkObject *object);
 static void  gtk_color_button_clicked(GtkButton *button);
