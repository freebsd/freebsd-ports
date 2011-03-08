--- setup2.py.orig	2010-11-05 06:19:08.000000000 +0800
+++ setup2.py	2011-03-08 08:12:34.000000000 +0800
@@ -36,7 +36,6 @@
                         'Please use capsule objects instead.',
                 category=DeprecationWarning)
 
-            import bsddb  # Import the 2.7 version, that uses CObject
         finally :
             context.__exit__()
 
@@ -50,10 +49,10 @@
             category=DeprecationWarning)
 
 
-try :
-  from setuptools import setup, Extension
-except :
-  from distutils.core import setup, Extension
+#try :
+#  from setuptools import setup, Extension
+#except :
+from distutils.core import setup, Extension
 
 from distutils.dep_util import newer
 import distutils.ccompiler
@@ -248,8 +247,8 @@
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = [dblib]
+    if not '-ldb-4.2' in LIBS:
+        libname = ['db-4.2']
     else:
         if debug: print "LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'"
         libname = []
