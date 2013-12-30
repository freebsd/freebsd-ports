--- src/pokerth.cpp.orig	2013-12-22 17:58:02.001816000 +0100
+++ src/pokerth.cpp	2013-12-23 12:36:37.581605099 +0100
@@ -34,8 +34,10 @@
 #include <ctime>
 #include <qapplication.h>
 
-#include <QtWidgets>
 #include <QtGui>
+#if QT_VERSION >= 0x050000
+#include <QtWidgets>
+#endif
 #include <QtCore>
 
 #ifdef __APPLE__
