--- setup.py.orig	2017-04-20 14:00:44 UTC
+++ setup.py
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
