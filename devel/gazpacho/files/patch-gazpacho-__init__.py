--- gazpacho/__init__.py.orig	2007-07-29 07:57:30 UTC
+++ gazpacho/__init__.py
@@ -16,19 +16,20 @@
 import os
 
 from kiwi.environ import Library
+from kiwi.environ import _KiwiProvider
 
 dirname = os.path.abspath(
     os.path.join(os.path.dirname(os.path.realpath(__file__)), '..'))
 
 lib = Library('gazpacho', root=dirname)
 if lib.uninstalled:
-    lib.add_global_resource('catalog', 'catalogs')
-    lib.add_global_resource('glade', 'glade')
-    lib.add_global_resource('resource', 'resources')
-    lib.add_global_resource('doc', '.')
-    lib.add_global_resource('pixmap', 'pixmaps')
-    lib.add_global_resource('pixmap', 'pixmaps/kiwi')
-    lib.add_global_resource('plugins', 'plugins')
+    _KiwiProvider.add_resource('catalog', os.path.join(dirname, 'catalog'))
+    _KiwiProvider.add_resource('glade', os.path.join(dirname, 'glade'))
+    _KiwiProvider.add_resource('resource', os.path.join(dirname, 'resources'))
+    _KiwiProvider.add_resource('doc', os.path.join(dirname, '.'))
+    _KiwiProvider.add_resource('pixmap', os.path.join(dirname, 'pixmaps'))
+    _KiwiProvider.add_resource('pixmap', os.path.join(dirname, 'pixmaps/kiwi'))
+    _KiwiProvider.add_resource('plugins', os.path.join(dirname, 'plugins'))
 lib.enable_translation()
 
 __version__ = "0.7.2"
