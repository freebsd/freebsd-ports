--- setup3.py.orig	2025-10-12 02:12:47 UTC
+++ setup3.py
@@ -39,7 +39,7 @@ import platform
 import platform
 
 
-from setuptools import setup, Extension
+from distutils.core import setup, Extension
 import distutils.ccompiler
 
 # read the module version number out of the .c file
@@ -282,8 +282,8 @@ if os.name == 'posix':
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if '-ldb' not in LIBS:
-        libname = [dblib]
+    if not '-l%%BDB_LIB_NAME%%' in LIBS:
+        libname = ['%%BDB_LIB_NAME%%']
     else:
         if debug:
             print("LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'")
@@ -292,7 +292,7 @@ if os.name == 'posix':
 
     # read db.h to figure out what version of Oracle Berkeley DB this is
     ver = None
-    with open(os.path.join(incdir, 'db.h'), 'r') as f :
+    with open('%%BDB_INCLUDE_DIR%%/db.h', 'r') as f :
         db_h_lines = f.readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
@@ -338,7 +338,7 @@ elif os.name == 'nt':
 
     # read db.h to figure out what version of Oracle Berkeley DB this is
     ver = None
-    with open(os.path.join(incdir, 'db.h'), 'r') as f :
+    with open('%%BDB_INCLUDE_DIR%%/db.h', 'r') as f :
         db_h_lines = f.readlines()
     db_ver_re = re.compile(
         r'^#define\s+DB_VERSION_STRING\s.*Berkeley DB (\d+\.\d+).*')
