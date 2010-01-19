
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -1,7 +1,4 @@
 import os, sys
-if sys.version_info >= (3,0):
-    from distribute_setup import use_setuptools
-    use_setuptools()
 from setuptools import setup
 
 long_description = """
