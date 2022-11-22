--- docs/conf.py.orig	2022-11-12 21:38:58 UTC
+++ docs/conf.py
@@ -1,9 +1,12 @@
+import os
 import subprocess
 import sys
 from datetime import date, datetime
 from pathlib import Path
 
 import sphinx_rtd_theme
+
+sys.path.insert(0, os.path.abspath('../build/lib'))
 
 from virtualenv.version import __version__
 
