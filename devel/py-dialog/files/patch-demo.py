--- demo.py.old	Mon Dec  5 01:13:57 2005
+++ demo.py	Mon Dec  5 01:14:02 2005
@@ -269,7 +269,7 @@
 #   If you want to use Xdialog (pathnames are also OK for the 'dialog'
 #   argument)
 #   d = dialog.Dialog(dialog="Xdialog", compat="Xdialog")
-    d = dialog.Dialog(dialog="dialog")
+    d = dialog.Dialog(dialog="cdialog")
 
     d.add_persistent_args(["--backtitle", "pythondialog demo"])
 
