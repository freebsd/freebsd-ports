$FreeBSD$
--- setup.py	2010-04-30 04:55:11.000000000 +0200
+++ setup.py.port	2010-05-06 18:14:16.000000000 +0200
@@ -4,8 +4,8 @@
 VERSION = '2.1.1'
 
 # Bootstrap installation of Distribute
-import distribute_setup
-distribute_setup.use_setuptools()
+#import distribute_setup
+#distribute_setup.use_setuptools()
 
 from setuptools import setup, find_packages
 
