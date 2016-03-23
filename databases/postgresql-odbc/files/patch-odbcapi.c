--- odbcapi.c.orig	2016-01-10 13:25:14 UTC
+++ odbcapi.c
@@ -913,11 +913,7 @@ RETCODE		SQL_API
 SQLExtendedFetch(HSTMT hstmt,
 				 SQLUSMALLINT fFetchType,
 				 SQLLEN irow,
-#if defined(WITH_UNIXODBC) && (SIZEOF_LONG != 8)
-				 SQLROWSETSIZE *pcrow,
-#else
 				 SQLULEN *pcrow,
-#endif /* WITH_UNIXODBC */
 				 SQLUSMALLINT *rgfRowStatus)
 {
 	RETCODE	ret;
@@ -927,17 +923,7 @@ SQLExtendedFetch(HSTMT hstmt,
 	ENTER_STMT_CS(stmt);
 	SC_clear_error(stmt);
 	StartRollbackState(stmt);
-#ifdef WITH_UNIXODBC
-	{
-		SQLULEN	retrieved;
-
-		ret = PGAPI_ExtendedFetch(hstmt, fFetchType, irow, &retrieved, rgfRowStatus, 0, SC_get_ARDF(stmt)->size_of_rowset_odbc2);
-		if (pcrow)
-			*pcrow = retrieved;
-	}
-#else
 	ret = PGAPI_ExtendedFetch(hstmt, fFetchType, irow, pcrow, rgfRowStatus, 0, SC_get_ARDF(stmt)->size_of_rowset_odbc2);
-#endif /* WITH_UNIXODBC */
 	stmt->transition_status = STMT_TRANSITION_EXTENDED_FETCH;
 	ret = DiscardStatementSvp(stmt, ret, FALSE);
 	LEAVE_STMT_CS(stmt);
