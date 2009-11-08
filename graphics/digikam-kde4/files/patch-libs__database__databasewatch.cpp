--- libs/database/databasewatch.cpp.orig	2009-03-17 01:28:48.000000000 +1000
+++ libs/database/databasewatch.cpp	2009-11-07 02:29:54.000000000 +1000
@@ -39,6 +39,7 @@
 // Local includes
 
 #include "collectionmanager.h"
+#include <unistd.h>
 
 Digikam_DatabaseWatchAdaptor::Digikam_DatabaseWatchAdaptor(Digikam::DatabaseWatch *watch)
                             : QDBusAbstractAdaptor(watch)
