--- services/object_storage/src/oci_cli_object_storage/objectstorage_cli_extended.py.orig	2023-06-07 19:09:16 UTC
+++ services/object_storage/src/oci_cli_object_storage/objectstorage_cli_extended.py
@@ -11,6 +11,7 @@ import os.path
 import math
 import os
 import os.path
+import shutil
 import stat
 import sys
 from mimetypes import guess_type
@@ -3079,7 +3080,7 @@ def _get_progress_bar_label(original_label, object_nam
     else:
         # If the names are too long then we can end up with multiple progress bars since we overflow a single line. To prevent
         # this, make sure that the label won't consume more than half the terminal width
-        terminal_width = click.termui.get_terminal_size()[0] / 2
+        terminal_width = shutil.get_terminal_size()[0] / 2
         remaining_width = terminal_width - (len(prefix) + 1)
 
         if len(object_name) > remaining_width:
