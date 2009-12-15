--- src/calibre/gui2/main.py.orig	2009-12-11 15:04:41.000000000 -0800
+++ src/calibre/gui2/main.py	2009-12-13 16:47:27.000000000 -0800
@@ -6,7 +6,7 @@
 from PyQt4.Qt import QCoreApplication, QIcon, QMessageBox
 
 from calibre import prints
-from calibre.constants import iswindows, __appname__, isosx
+from calibre.constants import iswindows, __appname__, isosx, isfreebsd
 from calibre.utils.ipc import ADDRESS, RC
 from calibre.gui2 import ORG_NAME, APP_UID, initialize_file_icon_provider, \
     Application
