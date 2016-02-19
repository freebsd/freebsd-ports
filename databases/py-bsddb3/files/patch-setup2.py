--- setup2.py.orig	2016-02-08 21:14:26 UTC
+++ setup2.py
@@ -81,11 +81,7 @@ if (sys.version_info[0] < 3) and (sys.ve
             category=DeprecationWarning)
 
 
-try :
-  from setuptools import setup, Extension
-except :
-  from distutils.core import setup, Extension
-
+from distutils.core import setup, Extension
 from distutils.dep_util import newer
 import distutils.ccompiler
 
@@ -288,8 +284,8 @@ if os.name == 'posix':
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
@@ -328,7 +324,7 @@ if os.name == 'posix':
 
     # read db.h to figure out what version of Berkeley DB this is
     ver = None
-    with open(os.path.join(incdir, 'db.h'), 'r') as f :
+    with open('%%BDB_INCLUDE_DIR%%/db.h', 'r') as f :
         db_h_lines = f.readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
