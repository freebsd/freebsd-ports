--- src/connection.h.orig	2014-12-30 18:40:27.628284595 +0100
+++ src/connection.h	2014-12-30 18:40:37.947283409 +0100
@@ -30,7 +30,7 @@
 #include "cache.h"
 #include "module.h"
 
-#include "spatialite/sqlite3.h"
+#include "spatialite/sqlite.h"
 #include "spatialite.h"
 
 SPATIALITE_DECLARE void spatialite_init(int verbose);
