--- ./aksetup_helper.py.orig	2010-12-17 17:12:20.000000000 +0100
+++ ./aksetup_helper.py	2010-12-17 17:12:30.000000000 +0100
@@ -1,11 +1,11 @@
 # dealings with ez_setup ------------------------------------------------------
-import distribute_setup
-distribute_setup.use_setuptools()
+#import distribute_setup
+#distribute_setup.use_setuptools()
 
 import setuptools
 from setuptools import Extension
 
-if 'distribute' not in setuptools.__file__:
+if False and 'distribute' not in setuptools.__file__:
     print "-------------------------------------------------------------------------"
     print "Setuptools conflict detected."
     print "-------------------------------------------------------------------------"
