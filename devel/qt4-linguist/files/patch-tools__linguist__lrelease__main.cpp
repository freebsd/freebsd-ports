--- ./tools/linguist/lrelease/main.cpp.orig	2010-11-06 04:55:12.000000000 +0300
+++ ./tools/linguist/lrelease/main.cpp	2010-11-11 17:08:48.303472069 +0300
@@ -45,6 +45,7 @@
 #ifndef QT_BOOTSTRAPPED
 #include <QtCore/QCoreApplication>
 #include <QtCore/QTranslator>
+#include <QtCore/QLibraryInfo>
 #endif
 #include <QtCore/QDebug>
 #include <QtCore/QDir>
