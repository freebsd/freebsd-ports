--- src/connection.h.orig	2013-11-22 09:33:35 UTC
+++ src/connection.h
@@ -30,7 +30,7 @@
 #include "cache.h"
 #include "module.h"
 
-#include "spatialite/sqlite3.h"
+#include "spatialite/sqlite.h"
 #include "spatialite.h"
 
 SPATIALITE_DECLARE void spatialite_init(int verbose);
