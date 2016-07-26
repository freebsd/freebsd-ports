--- setup.py.orig	2013-07-19 08:20:47 UTC
+++ setup.py
@@ -13,15 +13,13 @@ if os.name == "posix":
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
