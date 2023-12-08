- fix for https://github.com/luspi/photoqt/issues/20

--- cplusplus/main.cpp.orig	2023-12-08 05:19:26 UTC
+++ cplusplus/main.cpp
@@ -20,6 +20,8 @@
  **                                                                      **
  **************************************************************************/
 
+#include <clocale>
+
 #include <QQmlApplicationEngine>
 #include <QQmlContext>
 #include <QLoggingCategory>
