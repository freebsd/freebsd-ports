--- PythonCAD/Interface/Gtk/gtkimage.py.orig	2009-12-09 10:28:58.000000000 +0100
+++ PythonCAD/Interface/Gtk/gtkimage.py	2010-07-25 17:57:46.000000000 +0200
@@ -154,7 +154,7 @@
         self.__image = image
         self.__window = gtk.Window()
         self.__window.set_title(image.filename)
-        self.__window.set_icon_from_file("gtkpycad.png")
+        self.__window.set_icon_from_file("/usr/local/share/pixmaps/gtkpycad.png")
         self.__window.connect("destroy", self.__destroyEvent)
         self.__window.connect("event", self.__windowEvent)
         self.__window.connect("key_press_event", self.__keyPressEvent)
