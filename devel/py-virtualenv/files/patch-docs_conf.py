--- docs/conf.py.orig	2019-09-03 16:32:54 UTC
+++ docs/conf.py
@@ -5,6 +5,7 @@ import re
 import subprocess
 import sys
 from pathlib import Path
+sys.path.insert(0, os.path.abspath('../build/lib'))
 
 from virtualenv import __version__
 
