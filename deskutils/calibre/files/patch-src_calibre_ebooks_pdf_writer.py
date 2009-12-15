--- src/calibre/ebooks/pdf/writer.py.orig	2009-12-11 15:04:41.000000000 -0800
+++ src/calibre/ebooks/pdf/writer.py	2009-12-13 16:45:34.000000000 -0800
@@ -19,7 +19,7 @@
 from PyQt4 import QtCore
 from PyQt4.Qt import QUrl, QEventLoop, SIGNAL, QObject, \
     QPrinter, QMetaObject, QSizeF, Qt
-from PyQt4.QtWebKit import QWebView
+from PyQt4.QtWebKit import *
 
 from pyPdf import PdfFileWriter, PdfFileReader
 
