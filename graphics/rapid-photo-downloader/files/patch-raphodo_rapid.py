--- raphodo/rapid.py.orig	2020-04-17 01:22:23 UTC
+++ raphodo/rapid.py
@@ -96,7 +96,7 @@ from PyQt5.QtNetwork import QLocalSocket, QLocalServer
 import sip
 
 from raphodo.storage import (
-    ValidMounts, CameraHotplug, UDisks2Monitor, GVolumeMonitor, have_gio,
+    ValidMounts, CameraHotplug, GVolumeMonitor, have_gio,
     has_one_or_more_folders, mountPaths, get_desktop_environment, get_desktop,
     gvfs_controls_mounts, get_default_file_manager, validate_download_folder,
     validate_source_folder, get_fdo_cache_thumb_base_directory, WatchDownloadDirs, get_media_dir,
@@ -609,12 +609,12 @@ class RapidWindow(QMainWindow):
             self.prefs.backup_files = backup
         else:
             logging.info("Backing up files: %s", self.prefs.backup_files)
-            
+
         if backup_auto_detect is not None:
             self.prefs.backup_device_autodetection = backup_auto_detect
         elif self.prefs.backup_files:
             logging.info("Backup device auto detection: %s", self.prefs.backup_device_autodetection)
-            
+
         if photo_backup_identifier is not None:
             self.prefs.photo_backup_identifier = photo_backup_identifier
         elif self.prefs.backup_files and self.prefs.backup_device_autodetection:
@@ -624,7 +624,7 @@ class RapidWindow(QMainWindow):
             self.prefs.video_backup_identifier = video_backup_identifier
         elif self.prefs.backup_files and self.prefs.backup_device_autodetection:
             logging.info("video backup identifier: %s", self.prefs.video_backup_identifier)
-            
+
         if photo_backup_location is not None:
             self.prefs.backup_photo_location = photo_backup_location
         elif self.prefs.backup_files and not self.prefs.backup_device_autodetection:
@@ -939,18 +939,6 @@ class RapidWindow(QMainWindow):
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
@@ -2189,7 +2177,7 @@ class RapidWindow(QMainWindow):
             select_text=_('Select a destination folder')
         )
         self.photoDestination.addWidget(self.photoDestinationWidget)
-        
+
         self.videoDestinationDisplay = DestinationDisplay(
             menu=True, file_type=FileType.video, parent=self
         )
@@ -2655,11 +2643,11 @@ class RapidWindow(QMainWindow):
 
         body = _(
             r"""Please report the problem at <a href="{website}">{website}</a>.<br><br>
-            Include in your bug report the program's log files. The bug report must include 
-            <i>{log_file}</i>, but attaching the other log files is often helpful.<br><br> 
+            Include in your bug report the program's log files. The bug report must include
+            <i>{log_file}</i>, but attaching the other log files is often helpful.<br><br>
             If possible, please also include the program's configuration file
-            <i>{config_file}</i>.<br><br> 
-            Click <a href="{log_path}">here</a> to open the log directory, and 
+            <i>{config_file}</i>.<br><br>
+            Click <a href="{log_path}">here</a> to open the log directory, and
             <a href="{config_path}">here</a> to open the configuration directory.
             """
         ).format(
@@ -2695,7 +2683,7 @@ class RapidWindow(QMainWindow):
 
         :param message: the text to display
         :param rich_text: whether it text to display is in HTML format
-        :param title: optional title for message box, else defaults to 
+        :param title: optional title for message box, else defaults to
          localized 'Rapid Photo Downloader'
         :return: the message box
         """
@@ -4766,8 +4754,6 @@ Do you want to proceed with the download?
             self.sendTerminateToThread(self.backup_controller)
 
         if not self.gvfsControlsMounts:
-            self.udisks2MonitorThread.quit()
-            self.udisks2MonitorThread.wait()
             self.cameraHotplugThread.quit()
             self.cameraHotplugThread.wait()
         else:
@@ -5384,7 +5370,7 @@ Do you want to proceed with the download?
         After a preference change, rescan already scanned devices
         :param ignore_cameras: if True, don't rescan cameras
         :param rescan_path: if True, include manually specified paths
-         (i.e. This Computer)  
+         (i.e. This Computer)
         """
 
         if rescan_path:
@@ -6499,7 +6485,7 @@ def main():
     logger = iplogging.setup_main_process_logging(logging_level=logging_level)
 
     logging.info("Rapid Photo Downloader is starting")
-    
+
     if args.photo_renaming:
         photo_rename = args.photo_renaming == 'on'
         if photo_rename:
@@ -6508,7 +6494,7 @@ def main():
             logging.info("Photo renaming turned off from command line")
     else:
         photo_rename = None
-        
+
     if args.video_renaming:
         video_rename = args.video_renaming == 'on'
         if video_rename:
@@ -6569,13 +6555,13 @@ def main():
             logging.info("This Computer path set from command line: %s", this_computer_location)
         else:
             this_computer_location=None
-        
+
     if args.photo_location:
         photo_location = os.path.abspath(args.photo_location)
         logging.info("Photo location set from command line: %s", photo_location)
     else:
         photo_location=None
-        
+
     if args.video_location:
         video_location = os.path.abspath(args.video_location)
         logging.info("video location set from command line: %s", video_location)
