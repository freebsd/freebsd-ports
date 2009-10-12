--- src/calibre/gui2/viewer/main.py.orig	2009-10-11 19:16:59.000000000 +0400
+++ src/calibre/gui2/viewer/main.py	2009-10-11 19:17:14.000000000 +0400
@@ -19,7 +19,7 @@
                          info_dialog, error_dialog
 from calibre.ebooks.oeb.iterator import EbookIterator
 from calibre.ebooks import DRMError
-from calibre.constants import islinux
+from calibre.constants import islinux, isfreebsd
 from calibre.utils.config import Config, StringConfig, dynamic
 from calibre.gui2.search_box import SearchBox2
 from calibre.ebooks.metadata import MetaInformation
@@ -665,7 +665,7 @@
 def main(args=sys.argv):
     parser = option_parser()
     opts, args = parser.parse_args(args)
-    pid = os.fork() if False and islinux else -1
+    pid = os.fork() if False and (islinux or isfreebsd) else -1
     if pid <= 0:
         app = Application(args)
         app.setWindowIcon(QIcon(I('viewer.svg')))
