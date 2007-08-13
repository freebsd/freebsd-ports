--- src/ui-gtk2/gui_preferences.cc.orig	2007-08-12 19:50:46.000000000 +0200
+++ source/cantus/gui_preferences.cc	2007-08-12 19:51:17.000000000 +0200
@@ -81,7 +81,7 @@
   }
   Gtk::CheckButton *check = dynamic_cast<Gtk::CheckButton*>(widget);
   if (check) {
-    check->set_active((gboolean)value);
+    check->set_active(value);
     return TRUE;
   }
   return TRUE;
