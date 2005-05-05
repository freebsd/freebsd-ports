--- mssqldbmodule.c.orig	Thu May  5 17:32:37 2005
+++ mssqldbmodule.c	Thu May  5 17:43:36 2005
@@ -18,9 +18,9 @@
 	#include <sqlfront.h>
 	#include <sqldb.h>	   // DB-LIB header file (should always be included)
 #else
-	#include <sybfront.h>
-	#include <sybdb.h>	   // DB-LIB header file (should always be included)
-	#include <dblib.h>	   // DB-LIB header file (should always be included)
+	#include <tds.h>
+	#define _FREETDS_LIBRARY_SOURCE 1
+	#include <sybdb.h>
 
 	#define SQLNUMERIC    SYBNUMERIC    
 	#define SQLDECIMAL    SYBDECIMAL
@@ -115,7 +115,7 @@
 DBUSMALLINT     line;
 
 {
-	sprintf(_mssql_query_message,"SQL Server message %ld, state %d, severity %d:\n\t%s\n", msgno, msgstate, severity, msgtext);
+	sprintf(_mssql_query_message,"SQL Server message %ld, state %d, severity %d:\n\t%s\n", (long)msgno, msgstate, severity, msgtext);
 	return(0);
 }
 
@@ -203,7 +203,7 @@
 	dberrhandle(err_handler);
 	dbmsghandle(msg_handler);
 	// Set port
-	tds_set_port(login->tds_login, port);
+	//tds_set_port(login->tds_login, port);
 #endif
 
 
@@ -757,7 +757,7 @@
 					DBDATEREC di;
 					char strdi[25]={0,};
 					dbdatecrack(dbproc, &di, (DBDATETIME*)data);
-#ifdef MS_WIN32
+#if 1
 					sprintf(strdi, "%02d-%02d-%02d %02d:%02d:%02d", 
 							di.year,
 							di.month+1,
