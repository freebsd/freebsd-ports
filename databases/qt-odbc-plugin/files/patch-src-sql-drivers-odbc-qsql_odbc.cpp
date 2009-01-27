--- src/sql/drivers/odbc/qsql_odbc.cpp.orig	2009-01-26 23:43:41.000000000 +0600
+++ src/sql/drivers/odbc/qsql_odbc.cpp	2009-01-26 23:43:53.000000000 +0600
@@ -57,18 +57,8 @@
 #endif
 
 // newer platform SDKs use SQLLEN instead of SQLINTEGER
-#ifdef SQLLEN
 # define QSQLLEN SQLLEN
-#else
-# define QSQLLEN SQLINTEGER
-#endif
-
-#ifdef SQLULEN
 # define QSQLULEN SQLULEN
-#else
-# define QSQLULEN SQLUINTEGER
-#endif
-
 
 static const QSQLLEN COLNAMESIZE = 256;
 //Map Qt parameter types to ODBC types
