--- src/blockdiag/utils/bootstrap.py.orig	2020-02-01 09:48:17 UTC
+++ src/blockdiag/utils/bootstrap.py
@@ -255,11 +255,7 @@ class Options(object):
 def detectfont(options):
     import glob
     fontdirs = [
-        '/usr/share/fonts',
-        '/Library/Fonts',
-        '/System/Library/Fonts',
-        'c:/windows/fonts',
-        '/usr/local/share/font-*',
+        '/usr/local/share/fonts',
     ]
     fontfiles = [
         'ipagp.ttf',
