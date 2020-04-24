--- xlgui/devices.py.orig	2020-04-24 07:37:29 UTC
+++ xlgui/devices.py
@@ -42,7 +42,7 @@ class ManagerDialog(Gtk.Window):
 
     __gtype_name__ = 'DeviceManager'
 
-    tree_devices, model = GtkTemplate.Child.widgets(5)
+    tree_devices, model = GtkTemplate.Child.widgets(2)
 
     def __init__(self, parent, main):
         Gtk.Window.__init__(self)
