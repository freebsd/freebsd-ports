Obtained from:  https://github.com/sumerc/yappi/commit/778829f6f77928e4292e6a7dd4dfecf501f9a362

--- setup.py.orig	2019-01-18 09:41:09 UTC
+++ setup.py
@@ -1,13 +1,14 @@
 #!/usr/bin/env python
 
+import io
 import os
 import sys
 from setuptools import setup
 from distutils.core import Extension
 from distutils.ccompiler import new_compiler
 
-f = open('README.md')
-long_description = f.read()
+with io.open('README.md', encoding='UTF-8') as f:
+    long_description = f.read()
 
 HOMEPAGE = "https://github.com/sumerc/yappi"
 NAME = "yappi"
