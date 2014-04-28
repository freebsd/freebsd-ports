--- setup2.py.orig	2011-03-08 22:16:14.000000000 +0800
+++ setup2.py	2011-03-15 16:00:42.000000000 +0800
@@ -86,10 +86,7 @@
             category=DeprecationWarning)
 
 
-try :
-  from setuptools import setup, Extension
-except :
-  from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 from distutils.dep_util import newer
 import distutils.ccompiler
@@ -292,8 +289,8 @@
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
@@ -332,7 +329,7 @@
 
     # read db.h to figure out what version of Berkeley DB this is
     ver = None
-    db_h_lines = open(os.path.join(incdir, 'db.h'), 'r').readlines()
+    db_h_lines = open('%%BDB_INCLUDE_DIR%%/db.h', 'r').readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
     db_ver2 = db_ver
