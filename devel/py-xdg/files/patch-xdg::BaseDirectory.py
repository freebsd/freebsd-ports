--- xdg/BaseDirectory.py.orig	Wed Mar 23 00:08:43 2005
+++ xdg/BaseDirectory.py	Wed Mar 23 00:09:35 2005
@@ -33,7 +33,7 @@
 			os.path.join(_home, '.local', 'share'))
 
 xdg_data_dirs = [xdg_data_home] + \
-	os.environ.get('XDG_DATA_DIRS', '/usr/local/share:/usr/share').split(':')
+	os.environ.get('XDG_DATA_DIRS', '%%X11BASE%%/share/gnome:%%X11BASE%%/share:%%LOCALBASE%%/share:/usr/share').split(':')
 
 xdg_config_home = os.environ.get('XDG_CONFIG_HOME',
 			os.path.join(_home, '.config'))
