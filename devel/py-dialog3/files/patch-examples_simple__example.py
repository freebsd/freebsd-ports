--- examples/simple_example.py.orig	2016-05-07 16:38:28 UTC
+++ examples/simple_example.py
@@ -13,7 +13,7 @@ from dialog import Dialog
 locale.setlocale(locale.LC_ALL, '')
 
 # Initialize a dialog.Dialog instance
-d = Dialog(dialog="dialog")
+d = Dialog(dialog="cdialog")
 d.set_background_title("A Simple Example")
 
 
