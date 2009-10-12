--- src/calibre/constants.py.orig	2009-10-11 17:23:28.000000000 +0400
+++ src/calibre/constants.py	2009-10-11 18:02:53.000000000 +0400
@@ -22,7 +22,8 @@
 iswindows = 'win32' in sys.platform.lower() or 'win64' in sys.platform.lower()
 isosx     = 'darwin' in sys.platform.lower()
 isnewosx = isosx and getattr(sys, 'new_app_bundle', False)
-islinux   = not(iswindows or isosx)
+isfreebsd = 'freebsd' in sys.platform.lower()
+islinux   = not(iswindows or isosx or isfreebsd)
 isfrozen  = hasattr(sys, 'frozen')
 
 try:
