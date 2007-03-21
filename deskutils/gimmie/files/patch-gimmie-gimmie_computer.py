--- gimmie/gimmie_computer.py.orig	Sat Mar 17 16:41:46 2007
+++ gimmie/gimmie_computer.py	Sat Mar 17 16:43:07 2007
@@ -475,6 +475,8 @@
         self.face_monitor = FileMonitor(os.path.expanduser("~/.face"))
         self.face_monitor.open()
 
+	self.settings_menu_tree=None
+
     def do_reload(self):
         if gimmie_is_panel_applet():
             ### Show the Favorites source if in applet mode.  This is because
