--- setup.py.orig	1969-12-31 19:00:00.000000000 -0500
+++ setup.py	2009-02-09 11:03:10.000000000 -0500
@@ -0,0 +1,20 @@
+#!/usr/bin/env python
+
+from distutils.core import setup
+import os
+
+try:
+        os.rename('libs','dynagui_libs')
+except:
+        pass
+
+setup(  name='dynagui',
+        version='0.4',
+        description='GUI-based frontend for the dynamips emulator',
+        author='',
+        author_email='',
+        url='',
+        py_modules=['dynagui'],
+        packages=['dynagui_libs'],
+     )
+
