--- build/features.py	2018-10-28 12:33:56.000000000 -0500
+++ build/features.py	2018-11-06 14:58:04.915561000 -0500
@@ -105,13 +105,24 @@
             # -pthread tells GCC to do the right thing regardless of system
             build.env.Append(CCFLAGS='-pthread')
             build.env.Append(LINKFLAGS='-pthread')
+	elif build.platform_is_bsd:
+	    build.env.ParseConfig('pkg-config hidapi --silence-errors --cflags --libs')
 
+            conf.CheckLib(['pthread', 'libpthread'])
+            conf.CheckLib(['rt', 'librt'])
+
+            # -pthread tells GCC to do the right thing regardless of system
+            build.env.Append(CCFLAGS='-pthread')
+            build.env.Append(LINKFLAGS='-pthread')
         else:
             self.INTERNAL_LINK = True
             if build.platform_is_windows and not conf.CheckLib(['setupapi', 'libsetupapi']):
                 raise Exception('Did not find the setupapi library, exiting.')
             elif build.platform_is_osx:
                 build.env.AppendUnique(FRAMEWORKS=['IOKit', 'CoreFoundation'])
+            elif build.platform_is_bsd:
+                conf.CheckLib(['usb', 'libusb'])
+                conf.CheckLib(['usbhid', 'libusbhid'])
 
         build.env.Append(CPPDEFINES='__HID__')
         if self.INTERNAL_LINK:
@@ -129,7 +140,7 @@
                 # setupapi.
                 sources.append(
                     os.path.join(self.HIDAPI_INTERNAL_PATH, "windows/hid.c"))
-            elif build.platform_is_linux:
+            elif build.platform_is_linux or build.platform_is_bsd:
                 # hidapi compiles the libusb implementation by default on Linux
                 sources.append(
                     os.path.join(self.HIDAPI_INTERNAL_PATH, 'libusb/hid.c'))
@@ -147,14 +158,14 @@
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
 
@@ -162,12 +173,15 @@
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
 
@@ -396,7 +410,7 @@
         # If there is no system vamp-hostsdk is installed or if the version
         # of the installed vamp-hostsdk is less than the bundled version,
         # then we'll directly link the bundled vamp-hostsdk
-        if not conf.CheckLib('vamp-hostsdk') or not conf.CheckForPKG('vamp-plugin-sdk', '2.7.1'):
+        if not conf.CheckLib('vamp-hostsdk') or not conf.CheckForPKG('vamp-sdk', '2.7.1'):
             # For header includes
             build.env.Append(CPPPATH=[self.INTERNAL_VAMP_PATH])
             self.INTERNAL_LINK = True
@@ -409,7 +423,7 @@
         # FFTW3 support
         have_fftw3_h = conf.CheckHeader('fftw3.h')
         have_fftw3 = conf.CheckLib('fftw3', autoadd=False)
-        if have_fftw3_h and have_fftw3 and build.platform_is_linux:
+        if have_fftw3_h and have_fftw3 and (build.platform_is_linux or build.platform_is_bsd) :
             build.env.Append(CPPDEFINES='HAVE_FFTW3')
             build.env.ParseConfig(
                 'pkg-config fftw3 --silence-errors --cflags --libs')
@@ -1295,7 +1309,7 @@
             return ["util/battery/batterywindows.cpp"]
         elif build.platform_is_osx:
             return ["util/battery/batterymac.cpp"]
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             return ["util/battery/batterylinux.cpp"]
         else:
             raise Exception('Battery support is not implemented for the target platform.')
