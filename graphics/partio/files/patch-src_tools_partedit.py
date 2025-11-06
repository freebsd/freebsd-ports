--- src/tools/partedit.py.orig	2025-01-28 22:44:08 UTC
+++ src/tools/partedit.py
@@ -1080,7 +1080,7 @@ class PartEdit(QMainWindow):
     def dataDirtiedSlot(self, dirty):
         """ Sets the window title with or without "*" for dirty state """
 
-        title = self.data.filename
+        title = self.data.filename or ''
         if dirty:
             title += '*'
         self.setWindowTitle(title)
