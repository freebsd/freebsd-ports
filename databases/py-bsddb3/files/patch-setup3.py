--- setup3.py.orig	2009-06-30 14:58:24.819924337 +0800
+++ setup3.py	2009-06-30 14:59:39.207070800 +0800
@@ -204,8 +204,8 @@
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = [dblib]
+    if not '-l%%DBVERSION%%' in LIBS:
+        libname = ['%%DBVERSION%%']
     else:
         if debug: print("LIBS already contains '-ldb' not adding our own", "'-l"+dblib+"'")
         libname = []
