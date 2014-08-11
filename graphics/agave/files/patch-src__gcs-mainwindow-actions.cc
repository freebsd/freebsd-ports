--- src/gcs-mainwindow-actions.cc.orig
+++ src/gcs-mainwindow-actions.cc
@@ -25,7 +25,12 @@
 
 #include <vector>
 #include <gtk/gtk.h>
+
+#include <config.h>
+#ifdef HAVE_GNOME
 #include <libgnome/gnome-help.h>
+#endif // HAVE_GNOME
+
 #include <gtkmm/iconfactory.h>
 #include <gtkmm/stock.h>
 #include <gtkmm/clipboard.h>
@@ -251,9 +256,16 @@
     /* Help Menu Actions */
     void MainWindow::on_action_help_contents(void)
     {
+#ifdef HAVE_GNOME
         gnome_help_display("agave.xml",
                 NULL /* link id */,
                 NULL /* GError */);
+#else
+        gtk_show_uri(NULL,
+                "ghelp:agave",
+                gtk_get_current_event_time (),
+                NULL);
+#endif // HAVE_GNOME
     }
 
 
