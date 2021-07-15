--- driver/handle.cc.orig	2019-04-15 16:56:34 UTC
+++ driver/handle.cc
@@ -646,7 +646,7 @@ SQLRETURN SQL_API my_SQLFreeStmtExtended(SQLHSTMT hstm
 #if MYSQL_VERSION_ID >= 50722 && MYSQL_VERSION_ID < 80000
       if (stmt->result != NULL
 #else
-      if((stmt->result != NULL) && (stmt->result->field_alloc != NULL)
+      if((stmt->result != NULL) && (&stmt->result->field_alloc != NULL)
 #if (!MYSQLCLIENT_STATIC_LINKING || !MYSQL8)
          && (stmt->result->field_alloc.pre_alloc != NULL )
 #endif
