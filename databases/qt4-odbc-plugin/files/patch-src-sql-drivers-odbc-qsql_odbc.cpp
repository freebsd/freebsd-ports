--- src/sql/drivers/odbc/qsql_odbc.cpp.orig	2009-01-27 00:11:47.000000000 +0600
+++ src/sql/drivers/odbc/qsql_odbc.cpp	2009-01-27 00:12:12.000000000 +0600
@@ -64,17 +64,8 @@
 #endif
 
 // newer platform SDKs use SQLLEN instead of SQLINTEGER
-#if defined(SQLLEN) || defined(Q_OS_WIN64)
 # define QSQLLEN SQLLEN
-#else
-# define QSQLLEN SQLINTEGER
-#endif
-
-#if defined(SQLULEN) || defined(Q_OS_WIN64)
 # define QSQLULEN SQLULEN
-#else
-# define QSQLULEN SQLUINTEGER
-#endif
 
 static const int COLNAMESIZE = 256;
 //Map Qt parameter types to ODBC types
