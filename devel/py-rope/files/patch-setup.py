--- setup.py.orig	2011-05-12 09:26:24.000000000 +0800
+++ setup.py	2011-05-12 09:26:47.000000000 +0800
@@ -3,13 +3,7 @@
 import shutil
 
 extra_kwargs = {}
-try:
-    # we don't want to depend on setuptools
-    # please don't use any setuptools specific API
-    from setuptools import setup
-    extra_kwargs['test_suite'] = 'ropetest'
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 import rope
 
