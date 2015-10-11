--- setup.py.orig	2011-06-15 03:59:31.000000000 +0900
+++ setup.py	2012-09-28 07:03:50.000000000 +0900
@@ -61,17 +61,12 @@
       'icons/microphone.ico',
       'icons/microphone.png',
       'icons/pykaraoke.xpm',
-      'icons/splash.png']),
-    ('share/pykaraoke/fonts', [
-    'fonts/DejaVuSans.ttf',
-    'fonts/DejaVuSansCondensed.ttf',
-    'fonts/DejaVuSansCondensed-Bold.ttf',
-    ])]
+      'icons/splash.png'])]
 
 # These data files only make sense on Unix-like systems.
 if env != ENV_WINDOWS:
     data_files += [
-        ('bin', ['install/pykaraoke',
+        ('libexec', ['install/pykaraoke',
                  'install/pykaraoke_mini',
                  'install/pycdg',
                  'install/pykar',
