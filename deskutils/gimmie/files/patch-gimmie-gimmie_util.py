--- gimmie/gimmie_util.py.orig	Fri Jun  8 05:55:28 2007
+++ gimmie/gimmie_util.py	Sat Jun  9 17:21:25 2007
@@ -57,7 +57,8 @@
                 monitor_type = gnomevfs.MONITOR_DIRECTORY
             else:
                 monitor_type = gnomevfs.MONITOR_FILE
-            self.monitor = gnomevfs.monitor_add(self.path, monitor_type, self._queue_event)
+            if os.path.exists(self.path):
+                self.monitor = gnomevfs.monitor_add(self.path, monitor_type, self._queue_event)
 
     def _clear_timeout(self, info_uri):
         try:
@@ -736,7 +737,6 @@
     DEFAULT_BOOKMARKS = [
         ("firefox.desktop", "application/x-desktop", "gimmie.gimmie_applications.DesktopFileItem"),
         ("nautilus.desktop", "application/x-desktop", "gimmie.gimmie_applications.DesktopFileItem"),
-        (os.path.abspath("README"), "text/plain", "gimmie.gimmie_file.FileItem"),
         ("aim:goim?screenname=\"orphennui\"", "gaim/buddy", "gimmie.gimmie_gaim.GaimBuddy"),
         ]
     
