--- gamelib/data.py.orig	2009-04-08 03:18:37.000000000 +0400
+++ gamelib/data.py	2009-04-08 03:22:29.000000000 +0400
@@ -10,11 +10,7 @@
 import pyglet
 from pyglet import image
 
-data_py = os.path.abspath(os.path.dirname(__file__))
-if "library.zip" in data_py:
-    data_dir = os.path.normpath(os.path.join(data_py, '..', '..', 'data'))
-else:
-    data_dir = os.path.normpath(os.path.join(data_py, '..', 'data'))
+data_dir = "%%DATADIR%%"
 
 sys.path.insert(0, data_dir)
 
