--- setup.py.orig	2010-08-23 02:36:19.000000000 +0800
+++ setup.py	2010-11-12 14:34:24.000000000 +0800
@@ -13,15 +13,13 @@
         description = 'Offline Map Viewer',
         version = VERSION,
         url = WEB_ADDRESS,
-        data_files = [('share/doc/mapcatcher', ['README', 'changelog']),
-                    ('share/applications', ['gmapcatcher.desktop']),
-                    ('share/man/man1', 
-                        ['man/mapcatcher.1.gz', 'man/mapdownloader.1.gz']),
-                    ('share/pixmaps', ['images/mapcatcher.png']),
+        data_files = [('share/applications', ['gmapcatcher.desktop']),
+                    ('man/man1', 
+                        ['man/mapcatcher.1', 'man/mapdownloader.1']),
+                    ('share/pixmaps', ['images/map.png']),
                     ('share/pixmaps/gmapcatcher',
                     map(lambda(thestr): "images/" + thestr, os.listdir('images')))
         ],
-        scripts = ['mapcatcher', 'mapdownloader'],
         packages = ['gmapcatcher', 'gmapcatcher.mapServers', 
                     'gmapcatcher.pyGPSD', 'gmapcatcher.pyGPSD.nmea',
                     'gmapcatcher.pyGPSD.nmea.serial']
