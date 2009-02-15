--- setup.py~	2009-01-12 14:38:38.000000000 +0200
+++ setup.py	2009-01-12 15:03:21.000000000 +0200
@@ -23,7 +23,7 @@
 #
 import sys, os
 from warnings import warn
-from setuptools import setup, Extension
+from distutils.core import setup, Extension
 
 descr = "Python bindings for liblzma"
 long_descr = """PylibLZMA provides a python interface for the liblzma library
@@ -74,7 +74,6 @@
     ],
     py_modules = modules,
     ext_modules = extens,
-    test_suite = 'tests',
 )
 
 sys.exit(0)
