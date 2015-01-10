Fix ambiguity between GLib.Menu and Gtk.Menu (bug #8922)

--- src/extended-interface.vala.orig	2011-10-23 13:55:52 UTC
+++ src/extended-interface.vala
@@ -197,7 +197,7 @@ namespace Xfmpc {
 			this.context_menu.show_all ();
 		}
 
-		private void menu_detach (Widget attach_widget, Menu menu) {
+		private void menu_detach (Gtk.Widget attach_widget, Gtk.Menu menu) {
 		}
 
 		/*
