Fix build with Qt5-5.14

--- src/modules/console/autocompletemodel.cpp.orig	2020-04-04 11:36:31 UTC
+++ src/modules/console/autocompletemodel.cpp
@@ -1,4 +1,5 @@
 #include "autocompletemodel.h"
+#include <QFile>
 #include <QJsonDocument>
 #include <QJsonObject>
 #include <QJsonArray>
