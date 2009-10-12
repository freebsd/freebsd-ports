--- src/calibre/gui2/viewer/documentview.py.orig	2009-10-12 00:03:34.000000000 +0400
+++ src/calibre/gui2/viewer/documentview.py	2009-10-12 00:03:45.000000000 +0400
@@ -10,7 +10,7 @@
                      QPainter, QPalette, QBrush, QFontDatabase, QDialog, \
                      QColor, QPoint, QImage, QRegion, QVariant, \
                      QFont, QObject, QApplication, pyqtSignature
-from PyQt4.QtWebKit import QWebPage, QWebView, QWebSettings
+from PyQt4.QtWebKit import *
 
 from calibre.utils.config import Config, StringConfig
 from calibre.utils.localization import get_language
