--- doc/intro/intro.rst.orig	2015-04-04 09:43:57 UTC
+++ doc/intro/intro.rst
@@ -8,7 +8,7 @@ A minimal program using pythondialog starts with the c
 
   from dialog import Dialog
 
-  d = Dialog(dialog="dialog")
+  d = Dialog(dialog="cdialog")
 
 The *dialog* parameter indicates the executable to use to invoke the backend
 (which must be compatible with dialog_). For instance, one might use something
@@ -181,7 +181,7 @@ improve readability, we obtain the code for our exampl
   # This is almost always a good thing to do at the beginning of your programs.
   locale.setlocale(locale.LC_ALL, '')
 
-  d = Dialog(dialog="dialog")
+  d = Dialog(dialog="cdialog")
 
   button_names = {d.OK:     "OK",
                   d.CANCEL: "Cancel",
