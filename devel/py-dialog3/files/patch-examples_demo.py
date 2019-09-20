--- examples/demo.py.orig	2016-05-07 16:38:28 UTC
+++ examples/demo.py
@@ -335,7 +335,7 @@ class MyApp:
         # If you want to use Xdialog (pathnames are also OK for the 'dialog'
         # argument), you can use:
         #   dialog.Dialog(dialog="Xdialog", compat="Xdialog")
-        self.Dialog_instance = dialog.Dialog(dialog="dialog")
+        self.Dialog_instance = dialog.Dialog(dialog="cdialog")
         # See the module docstring at the top of the file to understand the
         # purpose of MyDialog.
         d = MyDialog(self.Dialog_instance)
