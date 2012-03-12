--- setup.py.orig	2012-01-06 11:21:39.000000000 +0800
+++ setup.py	2012-03-12 15:07:15.000000000 +0800
@@ -58,7 +58,7 @@
     # entry_points= scripts to create the appropriate .bat files.
     import setuptools
     _hush_pyflakes = [setuptools]
-    have_setuptools = True
+    have_setuptools = False
 except ImportError:
     pass
 
