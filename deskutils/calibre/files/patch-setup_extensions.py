--- setup/extensions.py.orig	2009-12-11 15:04:40.000000000 -0800
+++ setup/extensions.py	2009-12-14 18:25:26.000000000 -0800
@@ -11,7 +11,7 @@
 
 from PyQt4.pyqtconfig import QtGuiModuleMakefile
 
-from setup import Command, islinux, isosx, SRC, iswindows
+from setup import Command, islinux, isfreebsd, isosx, SRC, iswindows
 from setup.build_environment import fc_inc, fc_lib, \
         fc_error, poppler_libs, poppler_lib_dirs, poppler_inc_dirs, podofo_inc, \
         podofo_lib, podofo_error, poppler_error, pyqt, OSX_SDK, NMAKE, \
@@ -19,7 +19,7 @@
         magick_inc_dirs, magick_lib_dirs, png_lib_dirs, png_libs, \
         magick_error, magick_libs, ft_lib_dirs, ft_libs, jpg_libs, jpg_lib_dirs
 MT
-isunix = islinux or isosx
+isunix = islinux or isosx or isfreebsd
 
 make = 'make' if isunix else NMAKE
 
@@ -141,6 +141,11 @@
         ['calibre/devices/libusb.c'],
         ldflags=['-lusb-1.0']))
 
+if isfreebsd:
+    if os.environ.get('WITH_USB', 'no') == 'yes':
+        extensions.append(Extension('libusb',
+            ['calibre/devices/libusb.c'],
+            ldflags=['-lusb']))
 
 if isunix:
     cc = os.environ.get('CC', 'gcc')
@@ -160,6 +165,13 @@
     ldflags.append('-lpython'+sysconfig.get_python_version())
 
 
+if isfreebsd:
+    cflags.append('-pthread')
+    ldflags.append('-shared')
+    cflags.append('-I'+sysconfig.get_python_inc())
+    ldflags.append('-lpython'+sysconfig.get_python_version())
+
+
 if isosx:
     x, p = ('x86_64', 'ppc64') if leopard_build else ('i386', 'ppc')
     archs = ['-arch', x, '-arch', p, '-isysroot',
