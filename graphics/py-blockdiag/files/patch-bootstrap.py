--- src/blockdiag/utils/bootstrap.py.orig	2011-12-16 20:04:27.000000000 +0900
+++ src/blockdiag/utils/bootstrap.py	2011-12-29 11:15:27.000000000 +0900
@@ -170,13 +170,7 @@
 
 
 def detectfont(options):
-    fonts = ['c:/windows/fonts/VL-Gothic-Regular.ttf',  # for Windows
-             'c:/windows/fonts/msgothic.ttf',  # for Windows
-             'c:/windows/fonts/msgoth04.ttc',  # for Windows
-             '/usr/share/fonts/truetype/ipafont/ipagp.ttf',  # for Debian
-             '/usr/local/share/font-ipa/ipagp.otf',  # for FreeBSD
-             '/Library/Fonts/Hiragino Sans GB W3.otf',  # for MacOS
-             '/System/Library/Fonts/AppleGothic.ttf']  # for MacOS
+    ipafontpath = '%%LOCALBASE%%/share/font-ipa/ipagp.otf'
 
     fontpath = None
     if options.font:
@@ -190,11 +184,8 @@
             raise RuntimeError(msg)
 
     if fontpath is None:
-        for path in fonts:
-            _path, index = parse_fontpath(path)
-            if os.path.isfile(_path):
-                fontpath = path
-                break
+        if ipafontpath and os.path.isfile(ipafontpath):
+            fontpath = ipafontpath
 
     return fontpath
 
