--- driver/myutil.h.orig	2008-04-11 01:58:44.000000000 -0800
+++ driver/myutil.h	2009-01-08 11:50:41.000000000 -0900
@@ -174,7 +174,7 @@
 				      SQLLEN *pcbValue);
 SQLRETURN SQL_API my_SQLExtendedFetch(SQLHSTMT hstmt, SQLUSMALLINT fFetchType,
-				      SQLROWOFFSET irow, SQLULEN *pcrow,
-				      SQLUSMALLINT FAR *rgfRowStatus, bool upd_status);
+				      SQLLEN irow, SQLULEN *pcrow,
+				      SQLUSMALLINT FAR *rgfRowStatus, my_bool upd_status);
 SQLRETURN copy_stmt_error(STMT FAR *src, STMT FAR *dst);
 int unireg_to_c_datatype(MYSQL_FIELD *field);
 int default_c_type(int sql_data_type);
