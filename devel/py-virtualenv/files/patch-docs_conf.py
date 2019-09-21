--- docs/conf.py.orig	2019-09-03 16:32:54 UTC
+++ docs/conf.py
@@ -4,7 +4,11 @@ import os
 import re
 import subprocess
 import sys
-from pathlib import Path
+if sys.version_info[0] == 2:
+    from pathlib2 import Path
+else:
+    from pathlib import Path
+sys.path.insert(0, os.path.abspath('../build/lib'))
 
 from virtualenv import __version__
 
