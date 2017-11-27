--- coreSQLiteStudio/services/functionmanager.h.orig	2017-11-23 00:59:57 UTC
+++ coreSQLiteStudio/services/functionmanager.h
@@ -3,6 +3,7 @@
 
 #include "coreSQLiteStudio_global.h"
 #include "common/global.h"
+#include <QVariant> // upstream didn't fix the broken build for many months
 #include <QList>
 #include <QSharedPointer>
 #include <QObject>
