--- IPython/terminal/ptutils.py.orig	2020-10-30 18:09:09 UTC
+++ IPython/terminal/ptutils.py
@@ -20,6 +20,8 @@ from prompt_toolkit.patch_stdout import patch_stdout
 
 import pygments.lexers as pygments_lexers
 import os
+import sys
+import traceback
 
 _completion_sentinel = object()
 
