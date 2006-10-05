--- setup.py.orig	Wed Oct  4 01:11:36 2006
+++ setup.py	Wed Oct  4 01:11:55 2006
@@ -7,8 +7,6 @@
 from distutils.core import setup, Extension
 from distutils.command.install_data import install_data
 
-from pybookreader.config import program_version
-
 BUILD_FB2_SUPPORT = 1
 
 
@@ -36,7 +34,7 @@
 
 setup(
     name = 'PyBookReader',
-    version = program_version,
+    version = '0.5.0',
     url = 'http://pybookreader.narod.ru',
     author = 'Con Radchenko',
     author_email = 'pybookreader@narod.ru',
