--- examples/with-autowidgetsize/simple_example.py.orig	2016-05-07 16:38:28 UTC
+++ examples/with-autowidgetsize/simple_example.py
@@ -17,7 +17,7 @@ locale.setlocale(locale.LC_ALL, '')
 # With the 'autowidgetsize' option enabled, pythondialog's widget-producing
 # methods behave as if width=0, height=0, etc. had been passed, except where
 # these parameters are explicitely specified with different values.
-d = Dialog(dialog="dialog", autowidgetsize=True)
+d = Dialog(dialog="cdialog", autowidgetsize=True)
 d.set_background_title("A Simple Example")
 
 
