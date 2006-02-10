--- setup.py.orig	Thu Feb  2 09:01:31 2006
+++ setup.py	Fri Feb 10 12:19:00 2006
@@ -23,10 +23,7 @@
 
 import glob, os, sys
 
-from ez_setup import use_setuptools
-use_setuptools()
-
-from setuptools import setup, Extension
+from distutils.core import setup, Extension, Command
 
 # If you need to change anything, it should be enough to change setup.cfg.
 
