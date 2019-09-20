--- dialog.py.orig	2016-05-07 16:38:28 UTC
+++ dialog.py
@@ -878,7 +878,7 @@ class Dialog:
         # wants to know the (integer) error exit status, here it is...
         return self._DIALOG_ERROR
 
-    def __init__(self, dialog="dialog", DIALOGRC=None,
+    def __init__(self, dialog="cdialog", DIALOGRC=None,
                  compat="dialog", use_stdout=None, *, autowidgetsize=False,
                  pass_args_via_file=None):
         """Constructor for :class:`Dialog` instances.
