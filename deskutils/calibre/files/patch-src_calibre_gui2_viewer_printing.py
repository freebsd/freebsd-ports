--- src/calibre/gui2/viewer/printing.py.orig	2009-10-12 00:05:04.000000000 +0400
+++ src/calibre/gui2/viewer/printing.py	2009-10-12 00:05:09.000000000 +0400
@@ -12,7 +12,7 @@
 from PyQt4 import QtCore
 from PyQt4.Qt import QUrl, QEventLoop, SIGNAL,  QObject, QApplication, Qt, \
     QPrinter, QPrintPreviewDialog, QPrintDialog, QDialog, QMetaObject, Q_ARG
-from PyQt4.QtWebKit import QWebView
+from PyQt4.QtWebKit import *
 
 PRINTCSS = 'body{width:100%;margin:0;padding:0;font-family:Arial;color:#000;background:none;font-size:12pt;text-align:left;}h1,h2,h3,h4,h5,h6{font-family:Helvetica;}h1{font-size:19pt;}h2{font-size:17pt;}h3{font-size:15pt;}h4,h5,h6{font-size:12pt;}pre,code,samp{font:10ptCourier,monospace;white-space:pre-wrap;page-break-inside:avoid;}blockquote{margin:1.3em;padding:1em;font-size:10pt;}hr{background-color:#ccc;}aimg{border:none;}a:link,a:visited{background:transparent;font-weight:700;text-decoration:underline;color:#333;}a:link:after,a{color:#000;}table{margin:1px;text-align:left;}th{border-bottom:1pxsolid#333;font-weight:bold;}td{border-bottom:1pxsolid#333;}th,td{padding:4px10px4px0;}tfoot{font-style:italic;}caption{background:#fff;margin-bottom:2em;text-align:left;}thead{display:table-header-group;}tr{page-break-inside:avoid;}#header,.header,#footer,.footer,#navbar,.navbar,#navigation,.navigation,#rightSideBar,.rightSideBar,#leftSideBar,.leftSideBar{display:none;}'
 
