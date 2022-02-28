--- setup.py.orig	2021-12-29 08:31:32 UTC
+++ setup.py
@@ -2,7 +2,6 @@ import os
 import sys
 
 from setuptools import setup
-from m2r import convert
 
 
 def read(filename):
@@ -19,8 +18,8 @@ setup(
     author="Jayson Reis",
     author_email="santosdosreis@gmail.com",
     description="A pure python module to access memcached via its binary protocol with SASL auth support",
-    long_description="{0}\n{1}".format(
-        read("README.rst"), convert(read("CHANGELOG.md"))
+    long_description="{0}".format(
+        read("README.rst")
     ),
     url="https://github.com/jaysonsantos/python-binary-memcached",
     packages=["bmemcached", "bmemcached.client"],
