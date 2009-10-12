--- src/calibre/gui2/lrf_renderer/main.py.orig	2009-10-11 19:13:56.000000000 +0400
+++ src/calibre/gui2/lrf_renderer/main.py	2009-10-11 19:14:32.000000000 +0400
@@ -5,7 +5,7 @@
 from PyQt4.QtGui import QKeySequence, QPainter, QDialog, QSpinBox, QSlider, QIcon
 from PyQt4.QtCore import Qt, QObject, SIGNAL, QCoreApplication, QThread
 
-from calibre import __appname__, setup_cli_handlers, islinux
+from calibre import __appname__, setup_cli_handlers, islinux, isfreebsd
 from calibre.ebooks.lrf.lrfparser import LRFDocument
 
 from calibre.gui2 import ORG_NAME, APP_UID, error_dialog, \
@@ -255,7 +255,7 @@
         level = logging.DEBUG if opts.verbose else logging.INFO
         logger = logging.getLogger('lrfviewer')
         setup_cli_handlers(logger, level)
-    if islinux:
+    if islinux or isfreebsd:
         try: # Set lrfviewer as the default for LRF files for this user
             from subprocess import call
             call('xdg-mime default calibre-lrfviewer.desktop application/lrf', shell=True)
@@ -304,7 +304,7 @@
     if hasattr(opts, 'help'):
         parser.print_help()
         return 1
-    pid = os.fork() if islinux else -1
+    pid = os.fork() if (islinux or isfreebsd) else -1
     if pid <= 0:
         app = Application(args)
         app.setWindowIcon(QIcon(I('viewer.svg')))
