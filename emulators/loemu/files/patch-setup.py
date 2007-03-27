--- setup.py	Sat Mar 17 12:55:11 2007
+++ setup.py	Mon Mar 26 19:02:17 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!%%PYTHON_CMD%%
 from distutils.core import setup
 from glob import glob
 import sys
@@ -6,23 +6,6 @@
 if sys.hexversion < 0x020400f0:
     sys.stderr.write("python version failed: current version = %s.%s, needed version >= 2.4\n" % (sys.version_info[0],sys.version_info[1]))
     sys.exit(1)
-try:
-    import libxml2
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxml2\n") 
-    sys.exit(1)
-try:
-    import libxslt
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxslt1\n") 
-    sys.exit(1)
-try:
-    import gtk.glade
-except ImportError:
-    sys.stderr.write("dependencies failed: python glade\n") 
-    sys.exit(1)
-
-
 
 setup(name='loemu',
       version='0.1.1',
@@ -40,14 +23,14 @@
  * The generation of subsets of the gamelist is very fast.
 """,
       license='GNU GPL',
-      platforms='linux',
+      platforms='FreeBSD',
       packages=['loemu'],
       scripts=glob("scripts/*"),
       data_files=[
-                  ('share/games/loemu/config',glob("config/*")),
-                  ('share/games/loemu/glade',glob("glade/*")),
-                  ('share/games/loemu/roms',''),
-                  ('share/games/loemu/flyers',''),
-                  ('share/games/loemu/snaps',''),
+                  ('share/loemu/config',glob("config/*")),
+                  ('share/loemu/glade',glob("glade/*")),
+                  ('share/loemu/roms',''),
+                  ('share/loemu/flyers',''),
+                  ('share/loemu/snaps',''),
                   ]
       )
