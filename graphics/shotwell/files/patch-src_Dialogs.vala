--- src/Dialogs.vala.orig	2011-03-17 22:13:24.000000000 -0500
+++ src/Dialogs.vala	2011-03-17 22:14:45.000000000 -0500
@@ -1449,7 +1449,7 @@
                         ((FileIcon) app_icon).get_file().get_path()), Resources.DEFAULT_ICON_SCALE,
                         Gdk.InterpType.BILINEAR, false));
                 } else if (app_icon is ThemedIcon) {
-                    unowned Gdk.Pixbuf icon_pixbuf = 
+                    Gdk.Pixbuf icon_pixbuf = 
                         Gtk.IconTheme.get_default().load_icon(((ThemedIcon) app_icon).get_names()[0],
                         Resources.DEFAULT_ICON_SCALE, Gtk.IconLookupFlags.FORCE_SIZE);
                     
