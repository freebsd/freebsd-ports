--- setup.py.orig	Thu Jul 11 03:48:34 2002
+++ setup.py	Thu Jul 11 03:51:34 2002
@@ -68,8 +68,8 @@
     # figure out from the base setting where the lib and .h are
     if not incdir: incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir: libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = ['db']
+    if not '-l%%DBVERSION%%' in LIBS:
+        libname = ['%%DBVERSION%%']
     else:
         libname = []
     utils = []
@@ -93,7 +93,7 @@
     if not status and string.find(results, 'libdb.') >= 0:
         static = 1
 
-    if static:
+    if 0:
         print """\
 \aWARNING:
 \tIt appears that the old bsddb module is staticly linked in the
