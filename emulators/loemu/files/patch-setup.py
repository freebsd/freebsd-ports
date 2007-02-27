--- setup.py.orig	Tue Feb 27 14:25:52 2007
+++ setup.py	Tue Feb 27 14:26:23 2007
@@ -18,14 +18,14 @@
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
