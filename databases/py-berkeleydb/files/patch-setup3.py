--- setup3.py.orig	2021-05-19 15:44:48 UTC
+++ setup3.py
@@ -44,7 +44,7 @@ import glob
 # See https://setuptools.readthedocs.io/en/latest/deprecated/\
 #                                      distutils-legacy.html
 os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'local'
-from setuptools import setup, Extension
+from distutils.core import setup, Extension
 import distutils.ccompiler
 
 # read the module version number out of the .c file
@@ -256,8 +256,8 @@ if os.name == 'posix':
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
@@ -296,7 +296,7 @@ if os.name == 'posix':
 
     # read db.h to figure out what version of Oracle Berkeley DB this is
     ver = None
-    with open(os.path.join(incdir, 'db.h'), 'r') as f :
+    with open('%%BDB_INCLUDE_DIR%%/db.h', 'r') as f :
         db_h_lines = f.readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
