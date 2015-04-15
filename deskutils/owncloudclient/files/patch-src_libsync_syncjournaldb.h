--- src/libsync/syncjournaldb.h.orig	2015-03-16 14:28:58 UTC
+++ src/libsync/syncjournaldb.h
@@ -19,6 +19,8 @@
 #include <QDateTime>
 #include <QHash>
 
+#include <ctime>
+
 #include "utility.h"
 #include "ownsql.h"
 
