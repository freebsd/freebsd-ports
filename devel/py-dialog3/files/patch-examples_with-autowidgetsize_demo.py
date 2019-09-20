--- examples/with-autowidgetsize/demo.py.orig	2016-05-07 16:38:28 UTC
+++ examples/with-autowidgetsize/demo.py
@@ -340,7 +340,7 @@ class MyApp:
         # widget-producing methods behave as if width=0, height=0, etc. had
         # been passed, except where these parameters are explicitely specified
         # with different values.
-        self.Dialog_instance = dialog.Dialog(dialog="dialog",
+        self.Dialog_instance = dialog.Dialog(dialog="cdialog",
                                              autowidgetsize=True)
         # See the module docstring at the top of the file to understand the
         # purpose of MyDialog.
