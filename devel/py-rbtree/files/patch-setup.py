#
# Do not use py-setuptools
#
--- setup.py.orig	Thu Jun 15 02:43:12 2006
+++ setup.py	Mon Jul 10 12:12:43 2006
@@ -1,8 +1,6 @@
-import ez_setup
-ez_setup.use_setuptools()
-
-from setuptools import setup, find_packages
-from setuptools.extension import Extension
+from distutils.core import setup
+from distutils.extension import Extension
+from Pyrex.Distutils import build_ext
 
 classifiers = [
 "Development Status :: 4 - Beta",
@@ -31,4 +29,5 @@
                  include_dirs=['src',],
         ),
        ],
+    cmdclass = {'build_ext': build_ext}
     )
