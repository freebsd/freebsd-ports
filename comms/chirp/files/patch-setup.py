--- setup.py.orig	2012-03-24 02:01:12.000000000 -0500
+++ setup.py	2012-09-21 16:49:59.000000000 -0500
@@ -110,9 +110,9 @@
         data_files=[('share/applications', desktop_files),
                     ('share/chirp/images', image_files),
                     ('share/chirp', xsd_files),
-                    ('share/doc/chirp', ['COPYING']),
+#                    ('share/doc/chirp', ['COPYING']),
                     ('share/pixmaps', ['share/chirp.png']),
-                    ('share/man/man1', ["share/chirpw.1"]),
+                    ('man/man1', ["share/chirpw.1"]),
                     ('share/chirp/stock_configs', stock_configs),
                     ] + locale_files)
 
