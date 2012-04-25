--- src/blockdiag/utils/bootstrap.py.orig	2012-04-18 11:00:23.000000000 +0900
+++ src/blockdiag/utils/bootstrap.py	2012-04-23 11:34:13.000000000 +0900
@@ -182,23 +182,7 @@
 
 
 def detectfont(options):
-    fonts = [
-        # for Windows
-        'c:/windows/fonts/VL-Gothic-Regular.ttf',
-        'c:/windows/fonts/msgothic.ttf',
-        'c:/windows/fonts/msgoth04.ttc',
-        # for Debian (squeeze)
-        '/usr/share/fonts/truetype/ipafont/ipagp.ttf',
-        '/usr/share/fonts/truetype/vlgothic/VL-PGothic-Regular.ttf',
-        # for Debian (wheezy)
-        '/usr/share/fonts/opentype/ipafont-gothic/ipagp.ttf',
-        '/usr/share/fonts/truetype/vlgothic/VL-PGothic-Regular.ttf',
-        # for MacOS
-        '/Library/Fonts/Hiragino Sans GB W3.otf',  # for MacOS
-        '/System/Library/Fonts/AppleGothic.ttf',  # for MacOS
-        # for FreeBSD
-        '/usr/local/share/font-ipa/ipagp.otf',  # for FreeBSD
-    ]
+    ipafontpath = '%%LOCALBASE%%/share/font-ipa/ipagp.otf'
 
     fontpath = None
     if options.font:
@@ -212,11 +196,8 @@
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
 
