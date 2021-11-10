--- doc/help2rst.py.orig	2019-07-09 19:14:04 UTC
+++ doc/help2rst.py
@@ -63,6 +63,9 @@ def process(program, generate_headings, headings_chara
     elif '\noptional arguments:' in help:
         # argparse style
         help = help.split('\noptional arguments:', 1)[1]
+    elif '\noptions:' in help:
+        # argparse style, since python 3.10
+        help = help.split('\noptions:', 1)[1]
     else:
         raise SystemError('unexpected format of output for --help')
     # Remove any obsolete options
