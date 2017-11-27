--- coreSQLiteStudio/db/db.h.orig	2016-11-04 15:27:43 UTC
+++ coreSQLiteStudio/db/db.h
@@ -1,6 +1,7 @@
 #ifndef DB_H
 #define DB_H
 
+#include <QVariant> // upstream didn't fix the broken build for many months
 #include "returncode.h"
 #include "dialect.h"
 #include "services/functionmanager.h"
@@ -10,13 +11,13 @@
 #include "interruptable.h"
 #include "dbobjecttype.h"
 #include <QObject>
-#include <QVariant>
 #include <QList>
 #include <QHash>
 #include <QReadWriteLock>
 #include <QRunnable>
 #include <QStringList>
 #include <QSet>
+#include <QDataStream>
 
 /** @file */
 
