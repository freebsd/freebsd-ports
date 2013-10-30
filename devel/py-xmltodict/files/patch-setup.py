--- ./setup.py.orig	2013-10-21 11:53:07.000000000 +0300
+++ ./setup.py	2013-10-29 17:13:13.731011703 +0200
@@ -1,6 +1,6 @@
 #!/usr/bin/env python
 try:
-    from setuptools import setup
+    from distutils.core import setup
 except ImportError:
     from ez_setup import use_setuptools
     use_setuptools()
@@ -32,6 +32,5 @@
           'Programming Language :: Python :: Implementation :: PyPy',
           'Topic :: Text Processing :: Markup :: XML',
       ],
-      py_modules=['xmltodict'],
-      setup_requires=['nose>=1.0', 'coverage'],
+      py_modules=['xmltodict']
       )
