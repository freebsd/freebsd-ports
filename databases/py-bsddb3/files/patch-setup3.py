--- setup3.py.orig	2011-03-15 16:10:41.000000000 +0800
+++ setup3.py	2011-03-15 16:12:40.000000000 +0800
@@ -53,10 +53,7 @@
             category=DeprecationWarning)
 
 
-try :
-  from setuptools import setup, Extension
-except :
-  from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 from distutils.dep_util import newer
 import distutils.ccompiler
@@ -247,8 +244,8 @@
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = [dblib]
+    if not '-l%%DBVERSION%%' in LIBS:
+        libname = [%%DBVERSION%%]
     else:
         if debug: print("LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'")
         libname = []
