--- xdg/BaseDirectory.py.orig	2008-03-02 08:56:26.000000000 -0500
+++ xdg/BaseDirectory.py	2008-08-16 14:56:01.000000000 -0400
@@ -33,13 +33,13 @@ xdg_data_home = os.environ.get('XDG_DATA
             os.path.join(_home, '.local', 'share'))
 
 xdg_data_dirs = [xdg_data_home] + \
-    os.environ.get('XDG_DATA_DIRS', '/usr/local/share:/usr/share').split(':')
+    os.environ.get('XDG_DATA_DIRS', '%%LOCALBASE%%/share').split(':')
 
 xdg_config_home = os.environ.get('XDG_CONFIG_HOME',
             os.path.join(_home, '.config'))
 
 xdg_config_dirs = [xdg_config_home] + \
-    os.environ.get('XDG_CONFIG_DIRS', '/etc/xdg').split(':')
+    os.environ.get('XDG_CONFIG_DIRS', '%%LOCALBASE%%/etc/xdg').split(':')
 
 xdg_cache_home = os.environ.get('XDG_CACHE_HOME',
             os.path.join(_home, '.cache'))
