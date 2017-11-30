--- setup.py.orig	2017-11-09 11:09:27 UTC
+++ setup.py
@@ -0,0 +1,12 @@
+#!/usr/bin/env python
+
+from distutils.core import setup
+
+setup(name='pycanberra',
+      version='1.0',
+      description='A very basic (and incomplete) wrapper for libcanberra',
+      author='totdb',
+      author_email='gward@python.net',
+      url='https://github.com/totdb/pycanberra',
+      packages=['pycanberra'],
+     )
