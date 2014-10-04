--- imgtopslib/imgtops.py.orig	2014-10-04 21:42:40 UTC
+++ imgtopslib/imgtops.py
@@ -1,5 +1,5 @@
 import sys, os.path
-import Image
+from PIL import Image
 import cStringIO
 import time
 import getopt
