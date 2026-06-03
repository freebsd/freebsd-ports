--- xdg/BaseDirectory.py.orig	2012-12-06 22:07:26.000000000 +0100
+++ xdg/BaseDirectory.py	2014-03-04 17:22:23.000000000 +0100
@@ -32,13 +32,13 @@
             os.path.join(_home, '.local', 'share')
 
 xdg_data_dirs = [xdg_data_home] + \
-    (os.environ.get('XDG_DATA_DIRS') or '/usr/local/share:/usr/share').split(':')
+    (os.environ.get('XDG_DATA_DIRS') or '%%LOCALBASE%%/share').split(':')
 
 xdg_config_home = os.environ.get('XDG_CONFIG_HOME') or \
             os.path.join(_home, '.config')
 
 xdg_config_dirs = [xdg_config_home] + \
-    (os.environ.get('XDG_CONFIG_DIRS') or '/etc/xdg').split(':')
+    (os.environ.get('XDG_CONFIG_DIRS') or '%%LOCALBASE%%/etc/xdg').split(':')
 
 xdg_cache_home = os.environ.get('XDG_CACHE_HOME') or \
             os.path.join(_home, '.cache')
