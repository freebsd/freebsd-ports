--- driver/results.c.orig	2008-04-11 16:58:44.000000000 +0700
+++ driver/results.c	2009-01-27 00:01:01.000000000 +0600
@@ -1245,10 +1245,10 @@
 */
 SQLRETURN SQL_API my_SQLExtendedFetch( SQLHSTMT             hstmt,
                                        SQLUSMALLINT         fFetchType,
-                                       SQLROWOFFSET         irow,
+                                       SQLLEN               irow,
                                        SQLULEN             *pcrow,
                                        SQLUSMALLINT FAR    *rgfRowStatus,
-                                       bool                 upd_status )
+                                       my_bool                 upd_status )
 {
     ulong rows_to_fetch;
     long cur_row, max_row;
@@ -1511,19 +1511,16 @@
 
 SQLRETURN SQL_API SQLExtendedFetch( SQLHSTMT        hstmt,
                                     SQLUSMALLINT    fFetchType,
-                                    SQLROWOFFSET    irow,
-                                    SQLROWSETSIZE  *pcrow,
+                                    SQLLEN          irow,
+                                    SQLULEN        *pcrow,
                                     SQLUSMALLINT FAR *rgfRowStatus )
 {
     SQLRETURN rc;
-    SQLULEN rows;
     STMT_OPTIONS *options= &((STMT FAR *)hstmt)->stmt_options;
 
     options->rowStatusPtr_ex= rgfRowStatus;
 
-    rc= my_SQLExtendedFetch(hstmt, fFetchType, irow, &rows, rgfRowStatus, 1);
-    if (pcrow)
-      *pcrow= (SQLROWSETSIZE)rows;
+    rc= my_SQLExtendedFetch(hstmt, fFetchType, irow, pcrow, rgfRowStatus, 1);
 
     return rc;
 }
