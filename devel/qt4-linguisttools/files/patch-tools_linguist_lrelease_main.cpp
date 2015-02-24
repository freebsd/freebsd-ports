--- tools/linguist/lrelease/main.cpp.orig	2014-04-10 18:37:13 UTC
+++ tools/linguist/lrelease/main.cpp
@@ -47,6 +47,7 @@
 #ifndef QT_BOOTSTRAPPED
 #include <QtCore/QCoreApplication>
 #include <QtCore/QTranslator>
+#include <QtCore/QLibraryInfo>
 #endif
 #include <QtCore/QDebug>
 #include <QtCore/QDir>
