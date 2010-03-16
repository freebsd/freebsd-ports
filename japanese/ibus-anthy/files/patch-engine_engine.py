--- engine/engine.py.orig	2010-03-16 17:26:28.900007826 +0900
+++ engine/engine.py	2010-03-16 17:26:52.344325749 +0900
@@ -89,7 +89,7 @@
     It's better to load config.py(.in) in engine and setup instead and
     I will move KASUMI_IMG_PATH.
 '''
-KASUMI_IMG_PATH = "/usr/share/pixmaps/kasumi.png"
+KASUMI_IMG_PATH = "@@LOCALBASE@@/share/pixmaps/kasumi.png"
 
 KP_Table = {}
 for s in dir(keysyms):
