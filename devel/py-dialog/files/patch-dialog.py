
$FreeBSD$

--- dialog.py
+++ dialog.py
@@ -524,7 +524,7 @@
 
     """
 
-    def __init__(self, dialog="dialog", DIALOGRC=None, compat="dialog",
+    def __init__(self, dialog="cdialog", DIALOGRC=None, compat="dialog",
                  use_stdout=None):
         """Constructor for Dialog instances.
 
