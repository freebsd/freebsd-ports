--- src/medialib.vala.orig	2011-01-22 18:16:43.000000000 +0100
+++ src/medialib.vala	2011-05-11 15:02:36.000000000 +0200
@@ -588,14 +588,14 @@
 			close.connect(on_close);
 			response.connect(on_response);
 
-			Configurable.register(this);
+/*			Configurable.register(this); */
 			show_all();
 		}
 
 
 		private void on_close (Gtk.Dialog dialog)
 		{
-			Configurable.unregister(this);
+/*			Configurable.unregister(this); */
 		}
 
 
