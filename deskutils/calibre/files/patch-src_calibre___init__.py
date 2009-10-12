--- src/calibre/__init__.py.orig	2009-10-11 20:14:29.000000000 +0400
+++ src/calibre/__init__.py	2009-10-11 20:14:41.000000000 +0400
@@ -14,7 +14,7 @@
 from PyQt4.QtCore import QUrl
 from PyQt4.QtGui  import QDesktopServices
 from calibre.startup import plugins, winutil, winutilerror
-from calibre.constants import iswindows, isosx, islinux, isfrozen, \
+from calibre.constants import iswindows, isosx, islinux, isfreebsd, isfrozen, \
                               terminal_controller, preferred_encoding, \
                               __appname__, __version__, __author__, \
                               win32event, win32api, winerror, fcntl, \
