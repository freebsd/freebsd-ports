--- ./setup.py.orig	2012-05-27 06:05:41.000000000 +1000
+++ ./setup.py	2012-05-27 06:05:49.000000000 +1000
@@ -30,10 +30,7 @@
         'Programming Language :: Python'],
 }
 
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 setup(**sdict)
 
