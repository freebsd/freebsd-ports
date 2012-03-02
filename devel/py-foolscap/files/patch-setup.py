--- setup.py.orig	2012-01-06 11:21:39.000000000 +0800
+++ setup.py	2012-03-02 15:14:09.000000000 +0800
@@ -52,15 +52,6 @@
 }
 
 have_setuptools = False
-try:
-    # If setuptools is installed, then we'll add setuptools-specific
-    # arguments to the setup args. If we're on windows, this includes
-    # entry_points= scripts to create the appropriate .bat files.
-    import setuptools
-    _hush_pyflakes = [setuptools]
-    have_setuptools = True
-except ImportError:
-    pass
 
 if have_setuptools:
     import platform
