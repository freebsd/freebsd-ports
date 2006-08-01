--- setup.py	Tue Aug  1 02:32:46 2006
+++ setup.py	Tue Aug  1 02:33:30 2006
@@ -9,7 +9,7 @@
       url='http://pegueroles.cat/pyxmame',
       long_description='Allows you search, browse and launch games from a GTK interface.Looks good and its very responsive even with a lot of roms.',
       license='GNU GPL',
-      platforms='linux',
+      platforms='FreeBSD',
       packages=['pyxmame'],
       scripts=[
                'scripts/pyxmame',
@@ -18,10 +18,10 @@
                ],
       data_files=[
                   ('share/pixmaps/pyxmame',["pixmaps/penguin-revolt-128.png"]),
-                  ('share/games/pyxmame',["config/catver.ini"]),
-                  ('share/games/pyxmame/flyers',''),
-                  ('share/games/pyxmame/roms',''),
-                  ('share/games/pyxmame/snaps',''),
-                  ('/etc/pyxmame',["config/pyxmamerc"])
+                  ('share/pyxmame',["config/catver.ini"]),
+                  ('share/pyxmame/flyers',''),
+                  ('share/pyxmame/roms',''),
+                  ('share/pyxmame/snaps',''),
+                  ('etc/pyxmame',["config/pyxmamerc"])
                   ]
       )
