--- ext/mssql/php_mssql.h.orig  Tue Jun  8 11:24:27 2004
+++ ext/mssql/php_mssql.h       Tue Jun  8 11:23:39 2004
@@ -37,9 +37,7 @@
 #include "sqldb.h"

 #if HAVE_FREETDS
-#ifndef SHORT
-typedef short SHORT;
-#endif
+typedef short TDS_SHORT;
 #define SQLTEXT SYBTEXT
 #define SQLCHAR SYBCHAR
 #define SQLVARCHAR SYBVARCHAR
