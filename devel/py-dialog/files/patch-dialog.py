
$FreeBSD$

--- dialog.py.orig
+++ dialog.py
@@ -214,6 +214,8 @@
     "create_rc": lambda file: ("--create-rc", file),
     "defaultno": lambda enable: _simple_option("--defaultno", enable),
     "default_item": lambda string: ("--default-item", string),
+    "exit_label": lambda string: ("--exit-label", string),
+    "extra_button": lambda enable: _simple_option("--extra-button", enable),
     "help": lambda enable: _simple_option("--help", enable),
     "help_button": lambda enable: _simple_option("--help-button", enable),
     "help_label": lambda string: ("--help-label", string),
@@ -524,7 +526,7 @@
 
     """
 
-    def __init__(self, dialog="dialog", DIALOGRC=None, compat="dialog",
+    def __init__(self, dialog="cdialog", DIALOGRC=None, compat="dialog",
                  use_stdout=None):
         """Constructor for Dialog instances.
 
