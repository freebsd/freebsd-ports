--- setup/main.py.orig	2018-06-08 14:34:37 UTC
+++ setup/main.py
@@ -151,6 +151,7 @@ class Setup ():
         self.__window = self.__builder.get_object("SetupDialog")
         icon_file = os.path.join(config.pkgdatadir, "icons", "ibus-hangul.svg")
         self.__window.set_icon_from_file(icon_file)
+        self.__window.connect("destroy", Gtk.main_quit)
         self.__window.show()
 
         button = self.__builder.get_object("button_apply")
