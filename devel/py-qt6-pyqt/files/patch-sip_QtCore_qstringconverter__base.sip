Fix build with Qt 6.8.2

/wrkdirs/usr/ports/devel/py-qt6-pyqt/work-py311/PyQt6-6.8.0/build/QtCore/sipQtCoreQStringConverterBase.cpp:58:26:
error: call to implicitly-deleted copy constructor of '::QStringConvert
   58 |             sipCpp = new ::QStringConverterBase(*a0);

--- sip/QtCore/qstringconverter_base.sip.orig	2024-12-06 14:41:44 UTC
+++ sip/QtCore/qstringconverter_base.sip
@@ -22,7 +22,7 @@
 
 %If (Qt_6_4_0 -)
 
-class QStringConverterBase
+class QStringConverterBase /NoDefaultCtors/
 {
 %TypeHeaderCode
 #include <qstringconverter_base.h>
