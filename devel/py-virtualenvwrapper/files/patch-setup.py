--- ./setup.py.orig	2011-02-27 01:36:04.000000000 +0100
+++ ./setup.py	2011-03-02 23:31:19.000000000 +0100
@@ -6,8 +6,8 @@
 VERSION = '2.6.3'
 
 # Bootstrap installation of Distribute
-import distribute_setup
-distribute_setup.use_setuptools()
+#import distribute_setup
+#distribute_setup.use_setuptools()
 
 from setuptools import setup, find_packages
 
