--- src/blockdiag/utils/bootstrap.py.orig	2013-09-30 22:19:06.000000000 +0900
+++ src/blockdiag/utils/bootstrap.py	2014-01-02 16:19:04.000000000 +0900
@@ -222,11 +222,7 @@
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
