--- ./setup.py.orig	2010-11-09 12:03:46.000000000 +0100
+++ ./setup.py	2010-11-09 12:04:29.000000000 +0100
@@ -1,10 +1,7 @@
 #!/usr/bin/env python
 
-try:
-    from setuptools import setup
-except ImportError, excp:
-    from distutils.core import setup
-    
+from distutils.core import setup
+
 import pefile
 import os
 
