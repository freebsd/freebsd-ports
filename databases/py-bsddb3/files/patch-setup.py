--- setup.py.orig	Fri Jun  3 16:27:21 2005
+++ setup.py	Mon Oct 10 22:43:16 2005
@@ -197,8 +197,8 @@
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
@@ -221,7 +221,7 @@
     if not status and results.find('libdb.') >= 0:
         static = 1
 
-    if static:
+    if 0:
         print """\
 \aWARNING:
 \tIt appears that the old bsddb module is staticly linked in the
