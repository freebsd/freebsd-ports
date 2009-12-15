--- src/calibre/constants.py.orig	2009-12-11 15:04:40.000000000 -0800
+++ src/calibre/constants.py	2009-12-13 17:39:53.000000000 -0800
@@ -22,7 +22,8 @@
 iswindows = 'win32' in sys.platform.lower() or 'win64' in sys.platform.lower()
 isosx     = 'darwin' in sys.platform.lower()
 isnewosx = isosx and getattr(sys, 'new_app_bundle', False)
-islinux   = not(iswindows or isosx)
+isfreebsd = 'freebsd' in sys.platform.lower()
+islinux   = not(iswindows or isosx or isfreebsd)
 isfrozen  = hasattr(sys, 'frozen')
 
 try:
@@ -58,6 +59,7 @@
             'fontconfig', 'pdfreflow', 'progress_indicator'] + \
                     (['winutil'] if iswindows else []) + \
                     (['libusb'] if islinux else []) + \
+                    (['libusb'] if isfreebsd else []) + \
                     (['usbobserver'] if isosx else []):
             try:
                 p, err = __import__(plugin), ''
