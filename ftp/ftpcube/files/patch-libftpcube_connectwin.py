--- libftpcube/connectwin.py.orig	2009-05-01 23:03:48.000000000 +0200
+++ libftpcube/connectwin.py	2009-05-01 23:11:30.000000000 +0200
@@ -477,7 +477,7 @@
 
     def onBrowseClicked(self, event):
         """Displays a browser window to select a local directory."""
-        path = messages.displayFileDialog(self, _("Ftpcube - Browse"))
+        path = messages.displayDirDialog(self, _("Ftpcube - Browse"))
         if path:
             self.local_entry.SetValue(path)
 
@@ -664,4 +664,4 @@
             'delay' : int(self.delay_entry.GetValue()),
             'passive' : bool(self.passive_button.GetValue()),
         }
-        return opts
\ No newline at end of file
+        return opts
