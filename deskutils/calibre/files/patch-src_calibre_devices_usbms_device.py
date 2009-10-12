--- src/calibre/devices/usbms/device.py.orig	2009-10-11 19:19:08.000000000 +0400
+++ src/calibre/devices/usbms/device.py	2009-10-11 19:19:46.000000000 +0400
@@ -22,7 +22,7 @@
 from calibre.devices.interface import DevicePlugin
 from calibre.devices.errors import DeviceError, FreeSpaceError
 from calibre.devices.usbms.deviceconfig import DeviceConfig
-from calibre import iswindows, islinux, isosx, __appname__
+from calibre import iswindows, islinux, isosx, isfreebsd, __appname__
 from calibre.utils.filenames import ascii_filename as sanitize, shorten_components_to
 
 class Device(DeviceConfig, DevicePlugin):
@@ -554,7 +554,7 @@
     def open(self):
         time.sleep(5)
         self._main_prefix = self._card_a_prefix = self._card_b_prefix = None
-        if islinux:
+        if islinux or isfreebsd:
             try:
                 self.open_linux()
             except DeviceError:
@@ -621,7 +621,7 @@
                     pass
 
     def eject(self):
-        if islinux:
+        if islinux or isfreebsd:
             try:
                 self.eject_linux()
             except:
@@ -655,7 +655,7 @@
         self._linux_mount_map = {}
 
     def post_yank_cleanup(self):
-        if islinux:
+        if islinux or isfreebsd:
             try:
                 self.linux_post_yank()
             except:
