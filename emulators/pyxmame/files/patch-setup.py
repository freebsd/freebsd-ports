--- setup.py	Sat Sep 16 23:03:56 2006
+++ setup.py	Sat Sep 16 23:05:37 2006
@@ -16,16 +16,16 @@
   It uses a list of sets of images to show the game image.
 """,
       license='GNU GPL',
-      platforms='linux',
+      platforms='FreeBSD',
       packages=['pyxmame'],
       scripts=[
                'scripts/pyxmame'
                ],
       data_files=[
                   ('share/pixmaps/pyxmame',["pixmaps/penguin-revolt-128.png"]),
-                  ('share/games/pyxmame/flyers',''),
-                  ('share/games/pyxmame/roms',''),
-                  ('share/games/pyxmame/snaps',''),
-                  ('/etc/pyxmame',["config/pyxmamerc"])
+                  ('share/pyxmame/flyers',''),
+                  ('share/pyxmame/roms',''),
+                  ('share/pyxmame/snaps',''),
+                  ('etc/pyxmame',["config/pyxmamerc"])
                   ]
       )
