--- ./setup.py.orig	Fri Jan 27 17:35:03 2006
+++ ./setup.py	Fri Jan 27 17:35:26 2006
@@ -23,10 +23,7 @@
 
 import glob, os, sys
 
-from ez_setup import use_setuptools
-use_setuptools()
-
-from setuptools import setup, Extension, Command
+from distutils.core import setup, Extension, Command
 
 # If you need to change anything, it should be enough to change setup.cfg.
 
