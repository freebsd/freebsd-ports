--- src/calibre/ebooks/pdf/writer.py.orig	2009-10-11 23:06:22.000000000 +0400
+++ src/calibre/ebooks/pdf/writer.py	2009-10-11 23:18:59.000000000 +0400
@@ -19,7 +19,7 @@
 from PyQt4 import QtCore
 from PyQt4.Qt import QUrl, QEventLoop, SIGNAL, QObject, \
     QApplication, QPrinter, QMetaObject, QSizeF, Qt
-from PyQt4.QtWebKit import QWebView
+from PyQt4.QtWebKit import *
 
 from pyPdf import PdfFileWriter, PdfFileReader
 
