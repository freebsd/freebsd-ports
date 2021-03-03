--- setup.py.orig	2020-06-28 18:25:42 UTC
+++ setup.py
@@ -14,11 +14,9 @@
 
 from setuptools import find_packages, setup
 
-from version import __version__
-
 setup(
     name='opencensus-context',
-    version=__version__,  # noqa
+    use_scm_version=True,
     author='OpenCensus Authors',
     author_email='census-developers@googlegroups.com',
     classifiers=[
