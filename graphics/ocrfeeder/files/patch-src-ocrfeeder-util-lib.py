--- src/ocrfeeder/util/lib.py.orig	2012-01-16 23:38:47.000000000 +0800
+++ src/ocrfeeder/util/lib.py	2012-01-16 23:38:54.000000000 +0800
@@ -130,7 +130,7 @@
     return command
 
 def unpaperImage(configuration_manager, image_path):
-    tmp_dir = configuration_manager.temporary_dir
+    tmp_dir = configuration_manager.TEMPORARY_FOLDER
     prefix = os.path.splitext(image_path)[0]
     unpapered_name = os.path.join(tmp_dir, os.path.basename(prefix) + '.ppm')
     if os.path.exists(unpapered_name):
