The URL should be adapted with releases of x11/gnome-shell

--- gtweak/app.py.orig	2024-04-26 06:06:48 UTC
+++ gtweak/app.py
@@ -23,14 +23,10 @@ class ExtensionNotice(Gtk.MessageDialog):
         self.set_markup("<b>{0}</b>".format(_("Extensions Has Moved")))
 
         self.props.secondary_use_markup = True
-        self.props.secondary_text = "{0}\n\n{1}".format(
+        self.props.secondary_text = "{0}\n".format(
             # Translators: Placeholder will be replaced with "GNOME Extensions" in active link form
             _("Extensions management has been moved to {0}.").format(
-                '<a href="https://gitlab.gnome.org/GNOME/gnome-shell/-/blob/HEAD/subprojects/extensions-app/README.md">GNOME Extensions</a>',
-            ),
-            # Translators: Placeholder will be replaced with "Flathub" in active link form
-            _("We recommend downloading GNOME Extensions from {0} if your distribution does not include it.").format(
-                '<a href="https://flathub.org/apps/details/org.gnome.Extensions">Flathub</a>'
+                '<a href="https://gitlab.gnome.org/GNOME/gnome-shell/-/blob/HEAD/subprojects/extensions-app/README.md">GNOME Extensions</a>'
             )
         )
 
