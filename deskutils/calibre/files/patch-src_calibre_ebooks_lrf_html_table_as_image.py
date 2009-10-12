--- src/calibre/ebooks/lrf/html/table_as_image.py.orig	2009-10-12 00:04:02.000000000 +0400
+++ src/calibre/ebooks/lrf/html/table_as_image.py	2009-10-12 00:04:09.000000000 +0400
@@ -9,7 +9,7 @@
 import os, tempfile, atexit, shutil
 from PyQt4.Qt import QUrl, QApplication, QSize, QEventLoop, \
                      SIGNAL, QPainter, QImage, QObject, Qt
-from PyQt4.QtWebKit import QWebPage
+from PyQt4.QtWebKit import *
 
 
 class HTMLTableRenderer(QObject):
@@ -91,4 +91,4 @@
         QApplication([])
     tr = HTMLTableRenderer(html, base_dir, width, height, dpi, factor)
     tr.loop.exec_()
-    return tr.images, tr.tdir
\ No newline at end of file
+    return tr.images, tr.tdir
