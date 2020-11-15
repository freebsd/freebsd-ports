--- setup.py.orig	2010-05-05 05:55:08 UTC
+++ setup.py
@@ -1,8 +1,6 @@
 #!/usr/bin/env python
 """Distutils setup file"""
 
-import ez_setup
-ez_setup.use_setuptools()
 from setuptools import setup
 
 # Metadata
@@ -12,7 +10,7 @@ PACKAGES = ['peak', 'peak.util']
 
 def get_description():
     # Get our long description from the documentation
-    f = file('README.txt')
+    f = open('README.txt')
     lines = []
     for line in f:
         if not line.strip():
