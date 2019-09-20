--- doc/intro/example.py.orig	2015-04-04 09:43:57 UTC
+++ doc/intro/example.py
@@ -35,7 +35,7 @@ from dialog import Dialog
 # This is almost always a good thing to do at the beginning of your programs.
 locale.setlocale(locale.LC_ALL, '')
 
-d = Dialog(dialog="dialog")
+d = Dialog(dialog="cdialog")
 
 button_names = {d.OK:     "OK",
                 d.CANCEL: "Cancel",
