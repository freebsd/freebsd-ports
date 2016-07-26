--- build/features.py.orig	2013-05-08 23:20:26 UTC
+++ build/features.py
@@ -83,6 +83,9 @@ class HID(Feature):
         elif build.platform_is_osx:
             build.env.Append(LINKFLAGS='-framework IOKit')
             build.env.Append(LINKFLAGS='-framework CoreFoundation')
+        elif build.platform_is_bsd:
+            conf.CheckLib(['usb', 'libusb'])
+            conf.CheckLib(['usbhid', 'libusbhid'])
 
         build.env.Append(CPPDEFINES = '__HID__')
 
@@ -95,7 +98,7 @@ class HID(Feature):
             # Requires setupapi.lib which is included by the above check for
             # setupapi.
             sources.append(os.path.join(self.HIDAPI_INTERNAL_PATH, "windows/hid.c"))
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             sources.append(os.path.join(self.HIDAPI_INTERNAL_PATH, 'linux/hid-libusb.c'))
         elif build.platform_is_osx:
             sources.append(os.path.join(self.HIDAPI_INTERNAL_PATH, 'mac/hid.c'))
@@ -108,24 +111,27 @@ class Bulk(Feature):
     def enabled(self, build):
         # For now only make Bulk default on Linux only. Turn on for all
         # platforms after the 1.11.0 release.
-        is_default = 1 if build.platform_is_linux else 0
+        is_default = 1 if build.platform_is_linux or build.platform_is_bsd else 0
         build.flags['bulk'] = util.get_flags(build.env, 'bulk', is_default)
         if int(build.flags['bulk']):
             return True
         return False
 
     def add_options(self, build, vars):
-        is_default = 1 if build.platform_is_linux else 0
+        is_default = 1 if build.platform_is_linux or build.platform_is_bsd else 0
         vars.Add('bulk', 'Set to 1 to enable USB Bulk controller support.', is_default)
 
     def configure(self, build, conf):
         if not self.enabled(build):
             return
 
-        build.env.ParseConfig('pkg-config libusb-1.0 --silence-errors --cflags --libs')
-        if (not conf.CheckLib(['libusb-1.0', 'usb-1.0']) or
-            not conf.CheckHeader('libusb-1.0/libusb.h')):
-            raise Exception('Did not find the libusb 1.0 development library or its header file, exiting!')
+        if build.platform_is_linux:
+            build.env.ParseConfig('pkg-config libusb-1.0 --silence-errors --cflags --libs')
+            if (not conf.CheckLib(['libusb-1.0', 'usb-1.0']) or
+                not conf.CheckHeader('libusb-1.0/libusb.h')):
+                raise Exception('Did not find the libusb 1.0 development library or its header file, exiting!')
+        elif build.platform_is_bsd:
+            conf.CheckLib(['usb', 'libusb'])
 
         build.env.Append(CPPDEFINES = '__BULK__')
 
