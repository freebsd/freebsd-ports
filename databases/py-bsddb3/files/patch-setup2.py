--- setup2.py.orig	2010-11-05 06:19:08.000000000 +0800
+++ setup2.py	2011-01-10 16:51:14.000000000 +0800
@@ -50,10 +50,10 @@
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
@@ -248,8 +248,8 @@
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
