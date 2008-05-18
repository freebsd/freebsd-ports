--- db.c.orig	2008-05-09 19:34:45.288709828 -0400
+++ db.c	2008-05-09 19:35:37.495027112 -0400
@@ -326,7 +326,7 @@
     db_err( zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
             "db_query: Database query failed" );
   }
-  free(zSql);
+  sqlite3_free(zSql);
   if( sResult.azElem==0 ){
     db_query_callback(&sResult, 0, 0, 0);
   }
@@ -385,7 +385,7 @@
     db_err( zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
             "db_short_query: Database query failed" );
   }
-  free(zSql);
+  sqlite3_free(zSql);
   return zResult;
 }
 
@@ -409,7 +409,7 @@
   if( rc!=SQLITE_OK ){
     db_err(zErrMsg, zSql, "db_execute: Database execute failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
@@ -448,7 +448,7 @@
   if( rc!=SQLITE_OK ){
     db_err(zErrMsg, zSql, "db_exists: Database exists query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
   return iResult;
 }
 
@@ -470,6 +470,7 @@
   db_restrict_query(1);
   rc = sqlite3_exec(pDb, zSql, 0, 0, &zErrMsg);
   db_restrict_query(0);
+  sqlite3_free(zSql);
   return (rc!=SQLITE_OK) ? zErrMsg : 0;
 }
 
@@ -538,7 +539,7 @@
     db_err(zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
            "db_callback_query: Database query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
@@ -565,7 +566,7 @@
     db_err(zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
            "db_callback_execute: Database query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
