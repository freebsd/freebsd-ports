--- lib/runtime/db_sqlite.c.orig	2026-10-31 12:04:23 UTC
+++ lib/runtime/db_sqlite.c
@@ -6,7 +6,7 @@
  */
 
 #include "db_sqlite.h"
-#include "../../tools/vendor/sqlite/sqlite3.h"
+#include <sqlite3.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -37,6 +37,7 @@ int awktua_sqlite_open(const char *path, int flags, vo
         return rc;
     }
 
+    sqlite3_exec(db, "PRAGMA foreign_keys=ON", NULL, NULL, NULL);
     *out_db = db;
     return SQLITE_OK;
 }
