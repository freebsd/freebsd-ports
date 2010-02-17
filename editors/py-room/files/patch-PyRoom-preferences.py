--- PyRoom/preferences.py	2009-11-13 03:57:27.000000000 +0100
+++ PyRoom/preferences.py	2009-11-13 03:57:44.000000000 +0100
@@ -95,7 +95,7 @@
         self.conf_dir = os.path.join(config_home, 'pyroom')
         self.data_dir = os.path.join(data_home, 'pyroom')
         self.themes_dir  = os.path.join(self.data_dir, 'themes')
-        self.global_themes_dir = '/usr/share/pyroom/themes'
+        self.global_themes_dir = '%%PREFIX%%/share/pyroom/themes'
         # if we are not using a global installation,
         # take the themes directly from sources
         if not os.path.isdir(self.global_themes_dir) :
