--- setup.py.orig	2007-10-29 09:59:28.000000000 +0900
+++ setup.py	2007-10-29 10:01:54.000000000 +0900
@@ -1,6 +1,12 @@
 from setuptools import setup, find_packages
 from setuptools.extension import Extension
 
+# workaround to avoid erroneous workaround on setuptools
+import sys
+if sys.hexversion >= 0x2050000:
+    from setuptools.command import build_ext
+    del build_ext.build_ext.swig_sources
+
 setup(
     name="rbtree",
     version="0.8.0",
