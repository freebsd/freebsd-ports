--- imgtopslib/epstoimg.py.orig	2014-10-04 21:43:06 UTC
+++ imgtopslib/epstoimg.py
@@ -1,6 +1,6 @@
 import os, tempfile, sys
 import getopt
-import Image
+from PIL import Image
 from dimensions import interpret_dimension
 import re
 import cStringIO
