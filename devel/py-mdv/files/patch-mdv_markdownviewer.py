--- mdv/markdownviewer.py.orig	2016-12-07 10:29:16 UTC
+++ mdv/markdownviewer.py
@@ -129,7 +129,13 @@ Setting both to all will probably spin your beach ball
 import io
 import os
 import sys
+PY3 = True if sys.version_info[0] > 2 else False
 import textwrap
+
+ # adaptions:
+if PY3:
+    unichr = chr
+
 is_app = 0
 # code analysis for hilite:
 try:
