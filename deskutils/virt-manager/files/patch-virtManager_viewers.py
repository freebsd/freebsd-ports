--- virtManager/viewers.py.orig	2015-05-31 18:53:44 UTC
+++ virtManager/viewers.py
@@ -272,7 +272,7 @@ class VNCViewer(Viewer):
     ###################
 
     def _init_widget(self):
-        self._display = GtkVnc.Display.new()
+        self._display = GtkVnc.Display()
 
         # Make sure viewer doesn't force resize itself
         self._display.set_force_size(False)
