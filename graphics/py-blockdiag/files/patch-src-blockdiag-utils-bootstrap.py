--- src/blockdiag/utils/bootstrap.py.orig	2014-11-21 02:20:16 UTC
+++ src/blockdiag/utils/bootstrap.py
@@ -254,11 +254,7 @@ class Options(object):
 def detectfont(options):
     import glob
     fontdirs = [
-        '/usr/share/fonts',
-        '/Library/Fonts',
-        '/System/Library/Fonts',
-        'c:/windows/fonts',
-        '/usr/local/share/font-*',
+        '%%LOCALBASE%%/share/font-*',
     ]
     fontfiles = [
         'ipagp.ttf',
