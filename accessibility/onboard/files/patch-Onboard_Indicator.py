--- Onboard/Indicator.py.orig	2025-07-03 16:13:44 UTC
+++ Onboard/Indicator.py
@@ -133,7 +133,7 @@ class ContextMenu(GObject.GObject):
         self._keyboard.request_visibility_toggle()
 
     def _on_help(self, data=None):
-        subprocess.Popen(["/usr/bin/yelp", "help:onboard"])
+        subprocess.Popen(["%%LOCALBASE%%/bin/yelp", "help:onboard"])
 
     def _on_quit(self, data=None):
         _logger.debug("Entered _on_quit")
