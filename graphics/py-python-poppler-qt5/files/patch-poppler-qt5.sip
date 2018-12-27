--- poppler-qt5.sip.orig	2018-12-19 10:55:11 UTC
+++ poppler-qt5.sip
@@ -1,15 +1,18 @@
-%Module(name=popplerqt5, version=0)
+%Module(name=popplerqt5)
 
 /*
  * Bindings for Poppler-Qt5 to Python
  * Maintained by Wilbert Berendsen <wbsoft@xs4all.nl>
  */
 
+%Feature QTXML_AVAILABLE
 
 %Import QtCore/QtCoremod.sip
 %Import QtGui/QtGuimod.sip
 
-%Feature QTXML_AVAILABLE
+%If(QTXML_AVAILABLE)
+%Import QtXml/QtXmlmod.sip
+%End
 
 %Timeline {
     POPPLER_V0_20_0
