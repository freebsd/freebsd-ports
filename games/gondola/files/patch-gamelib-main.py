--- gamelib/main.py.orig	2009-04-08 03:23:54.000000000 +0400
+++ gamelib/main.py	2009-04-08 03:25:04.000000000 +0400
@@ -334,7 +334,7 @@
     player.pause()
 
     # Preload all data
-    for f in os.listdir("data"):
+    for f in os.listdir("%%DATADIR%%"):
         if f[-4:].endswith(".png"):
             data.load_texture(f)
 
