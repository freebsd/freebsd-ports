--- odbcapi.c.orig	2026-11-02 18:01:24 UTC
+++ odbcapi.c
@@ -1049,11 +1049,7 @@ SQLExtendedFetch(HSTMT hstmt,
 SQLExtendedFetch(HSTMT hstmt,
 				 SQLUSMALLINT fFetchType,
 				 SQLLEN irow,
-#if defined(WITH_UNIXODBC) && (SIZEOF_LONG_INT != 8)
-				 SQLROWSETSIZE *pcrow,
-#else
 				 SQLULEN *pcrow,
-#endif /* WITH_UNIXODBC */
 				 SQLUSMALLINT *rgfRowStatus)
 {
 	RETCODE	ret;
@@ -1066,17 +1062,7 @@ SQLExtendedFetch(HSTMT hstmt,
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
