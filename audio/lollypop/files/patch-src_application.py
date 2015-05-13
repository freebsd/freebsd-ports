--- src/application.py.orig	2015-04-30 06:37:18 UTC
+++ src/application.py
@@ -326,6 +326,7 @@ class Application(Gtk.Application):
 
         helpAction = Gio.SimpleAction.new('help', None)
         helpAction.connect('activate', self._help)
+        helpAction.set_enabled(False)
         self.set_accels_for_action('app.help', ["<Control>h"])
         self.add_action(helpAction)
 
