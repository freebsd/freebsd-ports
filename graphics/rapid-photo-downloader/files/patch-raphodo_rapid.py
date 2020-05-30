--- raphodo/rapid.py.orig	2020-05-03 17:31:45 UTC
+++ raphodo/rapid.py
@@ -97,7 +97,7 @@ from PyQt5.QtNetwork import QLocalSocket, QLocalServer
 import sip
 
 from raphodo.storage import (
-    ValidMounts, CameraHotplug, UDisks2Monitor, GVolumeMonitor, have_gio,
+    ValidMounts, CameraHotplug, GVolumeMonitor, have_gio,
     has_one_or_more_folders, mountPaths, get_desktop_environment, get_desktop,
     gvfs_controls_mounts, get_default_file_manager, validate_download_folder,
     validate_source_folder, get_fdo_cache_thumb_base_directory, WatchDownloadDirs, get_media_dir,
@@ -945,18 +945,6 @@ class RapidWindow(QMainWindow):
             logging.debug("Starting camera hotplug monitor...")
             QTimer.singleShot(0, self.cameraHotplugThread.start)
 
-            # Monitor when the user adds or removes a partition
-            self.udisks2Monitor = UDisks2Monitor(self.validMounts)
-            self.udisks2MonitorThread = QThread()
-            self.udisks2MonitorThread.started.connect(self.udisks2Monitor.startMonitor)
-            self.udisks2Unmount.connect(self.udisks2Monitor.unmount_volume)
-            self.udisks2Monitor.moveToThread(self.udisks2MonitorThread)
-            self.udisks2Monitor.partitionMounted.connect(self.partitionMounted)
-            self.udisks2Monitor.partitionUnmounted.connect(self.partitionUmounted)
-            # Start the monitor only on the thread it will be running on
-            logging.debug("Starting UDisks2 monitor...")
-            QTimer.singleShot(0, self.udisks2MonitorThread.start)
-
         if self.gvfsControlsMounts:
             # Gio.VolumeMonitor must be in the main thread, according to
             # Gnome documentation
@@ -4748,8 +4736,6 @@ Do you want to proceed with the download?
             self.sendTerminateToThread(self.backup_controller)
 
         if not self.gvfsControlsMounts:
-            self.udisks2MonitorThread.quit()
-            self.udisks2MonitorThread.wait()
             self.cameraHotplugThread.quit()
             self.cameraHotplugThread.wait()
         else:
