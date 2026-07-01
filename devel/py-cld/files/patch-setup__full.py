--- setup_full.py.orig	2026-07-01 18:54:51 UTC
+++ setup_full.py
@@ -15,7 +15,7 @@ from distutils.core import setup, Extension
 #
 
 from distutils.core import setup, Extension
-import distutils.core
+import setuptools
 import platform
 import subprocess
 import sys
@@ -30,7 +30,7 @@ CLD2_PATH = '../cld2'
 CLD2_PATH = '../cld2'
 
 # Test suite
-class cldtest(distutils.core.Command):
+class cldtest(setuptools.Command):
     # user_options, initialize_options and finalize_options must be overriden.
     user_options = []
     def initialize_options(self):
