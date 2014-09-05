--- setup2.py.orig	2011-03-08 22:16:14.000000000 +0800
+++ setup2.py	2011-03-15 16:00:42.000000000 +0800
@@ -86,11 +86,7 @@
             category=DeprecationWarning)
 
 
-try :
-  from setuptools import setup, Extension
-except :
-  from distutils.core import setup, Extension
-
+from distutils.core import setup, Extension
 from distutils.dep_util import newer
 import distutils.ccompiler
 
@@ -295,8 +291,8 @@
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = [dblib]
+    if not '-l%%DBVERSION%%' in LIBS:
+        libname = ['%%DBVERSION%%']
     else:
         if debug: print "LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'"
         libname = []
@@ -336,7 +332,7 @@
     # read db.h to figure out what version of Berkeley DB this is
     ver = None
     # This should move to "with" when we drop support for Python 2.4 and 2.5
-    f = open(os.path.join(incdir, 'db.h'), 'r')
+    f = open('%%BDB_INCLUDE_DIR%%/db.h', 'r')
     db_h_lines = f.readlines()
     f.close()
     db_ver_re = re.compile(
