--- setup.py.orig	2008-07-04 17:26:06.000000000 -0400
+++ setup.py	2008-07-04 17:26:18.000000000 -0400
@@ -1,7 +1,4 @@
-try:
-    from setuptools import setup, Extension
-except:
-    from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 import os
 from glob import glob
