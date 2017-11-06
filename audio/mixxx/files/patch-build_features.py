--- build/features.py.orig	2015-12-29 16:10:41 UTC
+++ build/features.py
@@ -87,6 +87,9 @@ class HID(Feature):
             raise Exception('Did not find the setupapi library, exiting.')
         elif build.platform_is_osx:
             build.env.AppendUnique(FRAMEWORKS=['IOKit', 'CoreFoundation'])
+        elif build.platform_is_bsd:
+            conf.CheckLib(['usb', 'libusb'])
+            conf.CheckLib(['usbhid', 'libusbhid'])
 
         build.env.Append(CPPDEFINES='__HID__')
 
@@ -100,7 +103,7 @@ class HID(Feature):
             # setupapi.
             sources.append(
                 os.path.join(self.HIDAPI_INTERNAL_PATH, "windows/hid.c"))
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             # hidapi compiles the libusb implementation by default on Linux
             sources.append(
                 os.path.join(self.HIDAPI_INTERNAL_PATH, 'libusb/hid.c'))
@@ -117,14 +120,14 @@ class Bulk(Feature):
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
         vars.Add('bulk',
                  'Set to 1 to enable USB Bulk controller support.', is_default)
 
@@ -132,12 +135,15 @@ class Bulk(Feature):
         if not self.enabled(build):
             return
 
-        build.env.ParseConfig(
-            'pkg-config libusb-1.0 --silence-errors --cflags --libs')
-        if (not conf.CheckLib(['libusb-1.0', 'usb-1.0']) or
-                not conf.CheckHeader('libusb-1.0/libusb.h')):
-            raise Exception(
-                'Did not find the libusb 1.0 development library or its header file, exiting!')
+        if build.platform_is_linux:
+            build.env.ParseConfig(
+                'pkg-config libusb-1.0 --silence-errors --cflags --libs')
+            if (not conf.CheckLib(['libusb-1.0', 'usb-1.0']) or
+                    not conf.CheckHeader('libusb-1.0/libusb.h')):
+                raise Exception(
+                    'Did not find the libusb 1.0 development library or its header file, exiting!')
+        elif build.platform_is_bsd:
+            conf.CheckLib(['usb', 'libusb'])
 
         build.env.Append(CPPDEFINES='__BULK__')
 
