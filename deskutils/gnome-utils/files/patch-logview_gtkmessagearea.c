--- logview/gtkmessagearea.c.orig	2009-03-21 17:23:53.000000000 -0400
+++ logview/gtkmessagearea.c	2009-03-21 17:24:08.000000000 -0400
@@ -33,6 +33,8 @@
 
 #include "gtkmessagearea.h"
 
+#include <stdlib.h>
+
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
