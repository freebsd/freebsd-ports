--- setup.py.orig	Mon Feb  3 11:28:52 2003
+++ setup.py	Mon Mar  3 16:22:31 2003
@@ -73,8 +73,8 @@
         incdir = os.path.join(BERKELEYDB_DIR, 'include')
     if not libdir:
         libdir = os.path.join(BERKELEYDB_DIR, 'lib')
-    if not '-ldb' in LIBS:
-        libname = ['db']
+    if not '-l%%DBVERSION%%' in LIBS:
+        libname = ['%%DBVERSION%%']
     else:
         libname = []
     utils = []
@@ -96,7 +96,7 @@
     if not status and results.find('libdb.') >= 0:
         static = 1
 
-    if static:
+    if 0:
         print """\
 \aWARNING:
 \tIt appears that the old bsddb module is staticly linked in the
