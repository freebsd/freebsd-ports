--- setup.py.orig	2016-07-26 12:20:39 UTC
+++ setup.py
@@ -28,13 +28,10 @@ from distutils import log
 from distutils.command.build_ext import build_ext as _build_ext
 from version import get_git_version
 
-try:
-    from setuptools import setup, Extension
-except ImportError:
-    from ez_setup import use_setuptools
-    use_setuptools()
+from ez_setup import use_setuptools
+use_setuptools()
 
-    from setuptools import setup, Extension
+from setuptools import setup, Extension
 
 class UnsupportedPlatformWarning(Warning):
     pass
