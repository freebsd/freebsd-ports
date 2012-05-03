--- mxSetup.py.orig	2012-04-15 04:10:16.579617284 +0600
+++ mxSetup.py	2012-04-15 04:10:32.020613836 +0600
@@ -315,7 +315,7 @@
 
     # This API was moved from distutils.sysconfig to distutils.ccompiler
     # in Python 2.7
-    from distutils.ccompiler import customize_compiler
+    from distutils.sysconfig import customize_compiler
 
 def get_python_include_dir():
 
