--- ./setup.py.orig	2013-12-04 01:18:48.000000000 +0000
+++ ./setup.py	2013-12-12 09:10:37.000000000 +0000
@@ -1,9 +1,6 @@
 #!/usr/bin/env python
 
-try:
-    from setuptools import setup
-except ImportError, excp:
-    from distutils.core import setup
+from distutils.core import setup
 
 import pefile
 import os
