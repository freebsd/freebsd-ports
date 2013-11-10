--- ./setup.py.orig	2013-07-23 04:02:25.000000000 +0400
+++ ./setup.py	2013-11-10 22:58:50.000000000 +0400
@@ -27,7 +27,7 @@
 
 try:
     from setuptools import setup
-    extra = dict(test_suite="tests.test.suite", include_package_data=True)
+    extra = dict(test_suite="tests.test.suite", include_package_data=True, zip_safe=False)
 except ImportError:
     from distutils.core import setup
     extra = {}
