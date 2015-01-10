Fix ambiguity between GLib.Menu and Gtk.Menu (bug #8922)

--- src/playlist.vala.orig	2011-10-23 15:02:51 UTC
+++ src/playlist.vala
@@ -98,7 +98,7 @@ namespace Xfmpc {
 							       new Gtk.Adjustment (0, 0, 0, 0, 0, 0));
 			scrolled.set_policy (Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.ALWAYS);
 
-			this.menu = new Menu ();
+			this.menu = new Gtk.Menu ();
 
 			var mi = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.REMOVE, null);
 			this.menu.append (mi);
