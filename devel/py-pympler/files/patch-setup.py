--- setup.py.orig	2012-12-29 14:55:15.000000000 -0200
+++ setup.py	2014-07-02 17:24:26.639875716 -0300
@@ -21,8 +21,8 @@
     _not_supported('Pympler requires Python 2.4 or newer')
 
 import os
-from distutils.command.build_py import build_py
-from distutils.command.install_lib import install_lib
+from setuptools.command.build_py import build_py
+from setuptools.command.install_lib import install_lib
 from distutils.core   import Command
 from distutils.core   import setup
 from distutils.dist   import Distribution
@@ -53,7 +53,7 @@
             data_path = cobj.install_data
             for line in fileinput.FileInput(module_file, inplace=True):
                 if line.startswith("DATA_PATH = "):
-                    line = "DATA_PATH = '%s'\n" % data_path
+                    line = "DATA_PATH = '%s'\n" % data_path.replace('%%STAGEDIR%%', '')
                 sys.stdout.write(line)
         build_py.build_module(self, module, module_file, package)
 
