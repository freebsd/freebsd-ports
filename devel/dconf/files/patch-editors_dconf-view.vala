--- editor/dconf-view.vala.orig	2013-05-01 21:48:19.000000000 +0000
+++ editor/dconf-view.vala	2013-05-01 21:50:26.000000000 +0000
@@ -270,7 +270,7 @@
 
     private void spin_edited_cb(Gtk.CellRendererText renderer, string path, string text)
     {
-        Key key = get_key_from_path(path);
+        var key = get_key_from_path(path);
         switch (key.type_string)
         {
         case "y":
