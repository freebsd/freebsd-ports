--- src/blockdiag/utils/bootstrap.py.orig	2021-12-06 16:43:47 UTC
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
+        '%%LOCALBASE%%/share/fonts',
     ]
     fontfiles = [
         'ipagp.ttf',
