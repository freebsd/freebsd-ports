--- src/calibre/gui2/__init__.py.orig	2009-12-11 15:04:41.000000000 -0800
+++ src/calibre/gui2/__init__.py	2009-12-13 16:46:37.000000000 -0800
@@ -9,7 +9,7 @@
 
 ORG_NAME = 'KovidsBrain'
 APP_UID  = 'libprs500'
-from calibre import islinux, iswindows, isosx
+from calibre import islinux, iswindows, isosx, isfreebsd
 from calibre.utils.config import Config, ConfigProxy, dynamic
 from calibre.utils.localization import set_qt_translator
 from calibre.ebooks.metadata.meta import get_metadata, metadata_from_formats
@@ -535,7 +535,7 @@
 
 def is_ok_to_use_qt():
     global gui_thread, _store_app
-    if islinux and ':' not in os.environ.get('DISPLAY', ''):
+    if (islinux or isfreebsd) and ':' not in os.environ.get('DISPLAY', ''):
         return False
     if _store_app is None and QApplication.instance() is None:
         _store_app = QApplication([])
