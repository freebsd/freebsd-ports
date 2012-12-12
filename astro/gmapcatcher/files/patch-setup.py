--- setup.py.orig	2012-10-17 02:09:15.000000000 +0800
+++ setup.py	2012-12-12 13:13:04.000000000 +0800
@@ -13,15 +13,13 @@
         description = 'Offline Map Viewer',
         version = VERSION,
         url = WEB_ADDRESS,
-        data_files = [('share/doc/mapcatcher', ['README', 'changelog']),
-                    ('share/applications', ['gmapcatcher.desktop']),
-                    ('share/man/man1',
+        data_files = [('share/applications', ['gmapcatcher.desktop']),
+                    ('man/man1',
                         ['man/mapcatcher.1.gz', 'man/mapdownloader.1.gz']),
                     ('share/pixmaps', ['images/mapcatcher.png']),
                     ('share/pixmaps/gmapcatcher',
                     map(lambda(thestr): "images/" + thestr, os.listdir('images')))
         ],
-        scripts = ['mapcatcher', 'mapdownloader'],
         packages = ['gmapcatcher', 'gmapcatcher.mapServers',
                     'gmapcatcher.tilesRepo', 'gmapcatcher.widgets',
                     'gmapcatcher.gpxpy', 'gmapcatcher.gps']
