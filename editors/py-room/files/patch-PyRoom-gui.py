--- PyRoom/gui.py.orig	2009-11-13 04:07:00.000000000 +0100
+++ PyRoom/gui.py	2009-11-13 04:07:12.000000000 +0100
@@ -53,7 +53,7 @@
 
         order of preference is homedir, global dir, source dir (if available)"""
         local_directory = os.path.join(data_home, 'pyroom', 'themes')
-        global_directory = '/usr/share/pyroom/themes' # FIXME: platform
+        global_directory = '%%PREFIX%%/share/pyroom/themes' # FIXME: platform
         # in case PyRoom is run without installation
         fallback_directory = os.path.join(
             os.path.dirname(os.path.abspath(__file__)),
