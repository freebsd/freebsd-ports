--- src/calibre/devices/scanner.py.orig	2011-11-11 20:22:34.000000000 -0800
+++ src/calibre/devices/scanner.py	2011-12-30 16:32:32.000000000 -0800
@@ -8,7 +8,7 @@
 import sys, os, re
 from threading import RLock
 
-from calibre.constants import iswindows, isosx, plugins, islinux
+from calibre.constants import iswindows, isosx, plugins, islinux, isfreebsd
 
 osx_scanner = win_scanner = linux_scanner = None
 
@@ -155,17 +155,80 @@
             ans.add(tuple(dev))
         return ans
 
+class FreeBSDScanner(object):
+
+    def __call__(self):
+        ans = set([])
+        import dbus
+        devs = []
+
+        try:
+           bus = dbus.SystemBus()
+           manager = dbus.Interface(bus.get_object('org.freedesktop.Hal',
+                         '/org/freedesktop/Hal/Manager'), 'org.freedesktop.Hal.Manager')
+           paths = manager.FindDeviceStringMatch('freebsd.driver','da')
+           for path in paths:
+              obj = bus.get_object('org.freedesktop.Hal', path)
+              objif = dbus.Interface(obj, 'org.freedesktop.Hal.Device')
+              devif = objif
+              parentdriver = None
+              while parentdriver != 'umass':
+                 try:
+                    obj = bus.get_object('org.freedesktop.Hal',
+                          objif.GetProperty('info.parent'))
+                    objif = dbus.Interface(obj, 'org.freedesktop.Hal.Device')
+                    try:
+                       parentdriver = objif.GetProperty('freebsd.driver')
+                    except dbus.exceptions.DBusException, e:
+                       continue
+                 except dbus.exceptions.DBusException, e:
+                    break
+              if parentdriver != 'umass':
+                  continue
+              dev = []
+              try:
+                 dev.append(objif.GetProperty('usb.vendor_id'))
+                 dev.append(objif.GetProperty('usb.product_id'))
+                 dev.append(objif.GetProperty('usb.device_revision_bcd'))
+              except dbus.exceptions.DBusException, e:
+                 continue
+              try:
+                 dev.append(objif.GetProperty('info.vendor'))
+              except:
+                 dev.append('')
+              try:
+                 dev.append(objif.GetProperty('info.product'))
+              except:
+                 dev.append('')
+              try:
+                 dev.append(objif.GetProperty('usb.serial'))
+              except:
+                 dev.append('')
+              dev.append(path)
+              ans.add(tuple(dev))
+        except dbus.exceptions.DBusException, e:
+           print >>sys.stderr, "Execution failed:", e
+        return ans
+
+
+
 linux_scanner = None
 
 if islinux:
     linux_scanner = LinuxScanner()
 
+freebsd_scanner = None
+
+if isfreebsd:
+    freebsd_scanner = FreeBSDScanner()
+
+
 class DeviceScanner(object):
 
     def __init__(self, *args):
         if isosx and osx_scanner is None:
             raise RuntimeError('The Python extension usbobserver must be available on OS X.')
-        self.scanner = win_scanner if iswindows else osx_scanner if isosx else linux_scanner
+        self.scanner = win_scanner if iswindows else osx_scanner if isosx else freebsd_scanner if isfreebsd else linux_scanner
         self.devices = []
 
     def scan(self):
