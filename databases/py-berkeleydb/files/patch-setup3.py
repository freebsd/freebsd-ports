--- setup3.py.orig	2020-12-07 19:17:41 UTC
+++ setup3.py
@@ -41,10 +41,7 @@ import sys
 import glob
 
 
-try :
-  from setuptools import setup, Extension
-except Exception:
-  from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 from distutils.dep_util import newer
 import distutils.ccompiler
@@ -258,8 +255,8 @@ if os.name == 'posix':
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = [dblib]
+    if not '-l%%BDB_LIB_NAME%%' in LIBS:
+        libname = ['%%BDB_LIB_NAME%%']
     else:
         if debug: print("LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'")
         libname = []
@@ -298,7 +295,7 @@ if os.name == 'posix':
 
     # read db.h to figure out what version of Oracle Berkeley DB this is
     ver = None
-    with open(os.path.join(incdir, 'db.h'), 'r') as f :
+    with open('%%BDB_INCLUDE_DIR%%/db.h', 'r') as f :
         db_h_lines = f.readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
