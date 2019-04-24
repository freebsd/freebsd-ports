--- gcb.cpp.orig	2019-03-06 00:33:25 UTC
+++ gcb.cpp
@@ -1,3 +1,4 @@
+#if USE_GCB
 #include <stdlib.h>
 #include "os-dep.h"
 #include <gtk/gtk.h>
@@ -6,6 +7,7 @@
 #include "gcin.h"
 #include "gcin-conf.h"
 
+void free_gcb();
 static GtkWidget *mainwin;
 static GtkClipboard *pclipboard_clipboard, *pclipboard_primary;
 static GtkWidget **buttonArr;
@@ -256,7 +258,7 @@ static void get_mouse_button( GtkWidget *widget,GdkEve
 
   }
 }
-
+#endif
 static void hist_get_mouse_button( GtkWidget *widget,GdkEventButton *event, gpointer data)
 {
   int i;
