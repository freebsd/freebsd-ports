--- setup.py.orig	2025-08-12 19:03:48 UTC
+++ setup.py
@@ -11,7 +11,10 @@ import sysconfig
 import subprocess
 import sys
 import sysconfig
-from setuptools.command.bdist_wheel import bdist_wheel
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel
+except:
+    from wheel.bdist_wheel import bdist_wheel
 
 if sys.platform == 'win32':
     # distutils is deprecated in Python 3.10 and removed in 3.12. However, it still works because Python defines a compatibility interface as long as setuptools is installed.
@@ -435,7 +438,7 @@ def awscrt_ext():
             # So it's simpler to link them in statically and have less runtime dependencies.
             #
             # Don't apply this trick to dependencies that are always on the OS (e.g. librt)
-            libraries = [':lib{}.a'.format(x) for x in libraries]
+            libraries = [':lib{}.so'.format(x) for x in libraries]
 
         # OpenBSD doesn't have librt; functions are found in libc instead.
         if not sys.platform.startswith('openbsd'):
