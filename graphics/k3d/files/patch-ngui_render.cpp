--- ngui/render.cpp.orig	2007-01-24 06:12:37.000000000 +0100
+++ ngui/render.cpp	2011-07-26 21:00:55.000000000 +0200
@@ -162,7 +162,7 @@
 		row[columns.separator] = false;
 	}
 
-	Gtk::ComboBox combo(model);
+	Gtk::ComboBox combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 
 	combo.pack_start(columns.icon, false);
 
@@ -286,7 +286,7 @@
 		row[columns.separator] = false;
 	}
 
-	Gtk::ComboBox combo(model);
+	Gtk::ComboBox combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 
 	combo.pack_start(columns.icon, false);
 
