main-window.vala:135.4-135.10: error: `Timeout' is an ambiguous reference
between `GLib.Timeout' and `Gtk.Timeout'
                        Timeout.add (1000, refresh);
                        ^^^^^^^

--- src/main-window.vala.orig	2011-10-23 15:08:38 UTC
+++ src/main-window.vala
@@ -132,7 +132,7 @@ namespace Xfmpc {
 			this.preferences.notify["show-statusbar"].connect (cb_show_statusbar_changed);
 
   	  	  	/* === Timeout === */
-			Timeout.add (1000, refresh);
+			GLib.Timeout.add (1000, refresh);
 		}
 
 		private void show_hide_status_icon () {
