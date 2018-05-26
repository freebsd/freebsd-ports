--- docs/conf.py.orig	2017-11-21 00:08:00 UTC
+++ docs/conf.py
@@ -15,10 +15,13 @@ import os
 import sphinx
 import sys
 
+if sys.version_info < (3,):
+    range = xrange
+
 sys.path.insert(0, os.path.pardir)
 import sorl
 
-for j in xrange(0, len(sphinx.__version__)):
+for j in range(0, len(sphinx.__version__)):
     try:
         version = float(sphinx.__version__[:-j])
         break
