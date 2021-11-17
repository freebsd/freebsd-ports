--- python/mozbuild/mozbuild/makeutil.py.orig	2021-03-15 15:52:38 UTC
+++ python/mozbuild/mozbuild/makeutil.py
@@ -7,7 +7,12 @@ from __future__ import absolute_import, print_function
 import os
 import re
 import six
-from collections import Iterable
+import sys
+
+if sys.version.startswith('2'):
+    from collections import Iterable
+else:
+    from collections.abc import Iterable
 
 
 class Makefile(object):
