Detection of "libmysqlclient" library is broken, so remove this check
--- modules/extra/m_mysql.cpp.orig	2015-04-23 14:25:58 UTC
+++ modules/extra/m_mysql.cpp
@@ -1,6 +1,3 @@
-/* RequiredLibraries: mysqlclient */
-/* RequiredWindowsLibraries: libmysql */
-
 #include "module.h"
 #include "modules/sql.h"
 #define NO_CLIENT_LONG_LONG
