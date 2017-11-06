--- bindings/python/setup.py.orig	2017-03-10 18:03:11 UTC
+++ bindings/python/setup.py
@@ -1,10 +1,7 @@
 #!/usr/bin/env python
 import os
 
-try:
-    from setuptools import setup, Extension
-except ImportError:
-    sys.exit('The setup requires setuptools.')
+from distutils.core import setup, Extension
 
 TOP_SRCDIR = os.environ.get('ABS_TOP_SRCDIR', '../..')
 TOP_BUILDDIR = os.environ.get('ABS_TOP_BUILDDIR', '../..')
