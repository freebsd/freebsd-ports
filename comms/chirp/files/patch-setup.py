--- setup.py.orig	2015-03-05 08:00:18 UTC
+++ setup.py
@@ -109,7 +109,7 @@ def default_build():
 
     desktop_files = glob("share/*.desktop")
     # form_files = glob("forms/*.x?l")
-    image_files = glob("images/*")
+#    image_files = glob("images/*")
     _locale_files = glob("locale/*/LC_MESSAGES/CHIRP.mo")
     stock_configs = glob("stock_configs/*")
 
@@ -127,11 +127,11 @@ def default_build():
         version=CHIRP_VERSION,
         scripts=["chirpw"],
         data_files=[('share/applications', desktop_files),
-                    ('share/chirp/images', image_files),
+#                    ('share/chirp/images', image_files),
                     ('share/chirp', xsd_files),
-                    ('share/doc/chirp', ['COPYING']),
+#                    ('share/doc/chirp', ['COPYING']),
                     ('share/pixmaps', ['share/chirp.png']),
-                    ('share/man/man1', ["share/chirpw.1"]),
+                    ('man/man1', ["share/chirpw.1"]),
                     ('share/chirp/stock_configs', stock_configs),
                     ] + locale_files)
 
