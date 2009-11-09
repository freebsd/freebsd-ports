--- ./db.c.orig	2007-01-28 13:40:07.000000000 -0500
+++ ./db.c	2009-11-09 17:15:57.000000000 -0500
@@ -125,7 +125,6 @@
 ** routine NULLs-out fields of the database we do not want arbitrary
 ** users to see, such as the USER.PASSWD field.
 */
-extern int sqlite3StrICmp(const char*, const char*);
 static int access_authorizer(
   void *NotUsed,
   int type,
@@ -141,34 +140,34 @@
     return SQLITE_OK;
 #endif
   }else if( type==SQLITE_READ ){
-    if( sqlite3StrICmp(zArg1,"user")==0 ){
-      if( sqlite3StrICmp(zArg2,"passwd")==0 || sqlite3StrICmp(zArg2,"email")==0 ){
+    if( strcasecmp(zArg1,"user")==0 ){
+      if( strcasecmp(zArg2,"passwd")==0 || strcasecmp(zArg2,"email")==0 ){
         return SQLITE_IGNORE;
       }
-    }else if( sqlite3StrICmp(zArg1, "cookie")==0 ){
+    }else if( strcasecmp(zArg1, "cookie")==0 ){
       return SQLITE_IGNORE;
-    }else if( sqlite3StrICmp(zArg1, "config")==0 ){
+    }else if( strcasecmp(zArg1, "config")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okSetup && sqlite3StrICmp(zArg1, "access_load")==0 ){
+    }else if( !g.okSetup && strcasecmp(zArg1, "access_load")==0 ){
       return SQLITE_IGNORE;
-    }else if( (!g.okWrite || g.isAnon) && sqlite3StrICmp(zArg1,"ticket")==0
-        && sqlite3StrICmp(zArg2,"contact")==0){
+    }else if( (!g.okWrite || g.isAnon) && strcasecmp(zArg1,"ticket")==0
+        && strcasecmp(zArg2,"contact")==0){
       return SQLITE_IGNORE;
-    }else if( !g.okCheckout && sqlite3StrICmp(zArg1,"chng")==0 ){
+    }else if( !g.okCheckout && strcasecmp(zArg1,"chng")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okCheckout && sqlite3StrICmp(zArg1,"filechng")==0 ){
+    }else if( !g.okCheckout && strcasecmp(zArg1,"filechng")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okCheckout && sqlite3StrICmp(zArg1,"file")==0 ){
+    }else if( !g.okCheckout && strcasecmp(zArg1,"file")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okCheckout && sqlite3StrICmp(zArg1,"inspect")==0 ){
+    }else if( !g.okCheckout && strcasecmp(zArg1,"inspect")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okRead && sqlite3StrICmp(zArg1,"ticket")==0 ){
+    }else if( !g.okRead && strcasecmp(zArg1,"ticket")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okRead && sqlite3StrICmp(zArg1,"tktchng")==0 ){
+    }else if( !g.okRead && strcasecmp(zArg1,"tktchng")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okRdWiki && sqlite3StrICmp(zArg1,"attachment")==0 ){
+    }else if( !g.okRdWiki && strcasecmp(zArg1,"attachment")==0 ){
       return SQLITE_IGNORE;
-    }else if( !g.okRdWiki && sqlite3StrICmp(zArg1,"wiki")==0 ){
+    }else if( !g.okRdWiki && strcasecmp(zArg1,"wiki")==0 ){
       return SQLITE_IGNORE;
     }
     return SQLITE_OK;
@@ -326,7 +325,7 @@
     db_err( zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
             "db_query: Database query failed" );
   }
-  free(zSql);
+  sqlite3_free(zSql);
   if( sResult.azElem==0 ){
     db_query_callback(&sResult, 0, 0, 0);
   }
@@ -385,7 +384,7 @@
     db_err( zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
             "db_short_query: Database query failed" );
   }
-  free(zSql);
+  sqlite3_free(zSql);
   return zResult;
 }
 
@@ -409,7 +408,7 @@
   if( rc!=SQLITE_OK ){
     db_err(zErrMsg, zSql, "db_execute: Database execute failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
@@ -448,7 +447,7 @@
   if( rc!=SQLITE_OK ){
     db_err(zErrMsg, zSql, "db_exists: Database exists query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
   return iResult;
 }
 
@@ -470,6 +469,7 @@
   db_restrict_query(1);
   rc = sqlite3_exec(pDb, zSql, 0, 0, &zErrMsg);
   db_restrict_query(0);
+  sqlite3_free(zSql);
   return (rc!=SQLITE_OK) ? zErrMsg : 0;
 }
 
@@ -538,7 +538,7 @@
     db_err(zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
            "db_callback_query: Database query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
@@ -565,7 +565,7 @@
     db_err(zErrMsg ? zErrMsg : sqlite3_errmsg(pDb), zSql,
            "db_callback_execute: Database query failed");
   }
-  free(zSql);
+  sqlite3_free(zSql);
 }
 
 /*
@@ -672,7 +672,6 @@
 ** name as an argument and returns the value that the user enters in the
 ** resulting HTML form. A second optional parameter provides a default value.
 */
-extern int sqlite3StrICmp(const char*, const char*);
 static void f_aux(sqlite3_context *context, int argc, sqlite3_value **argv){
   int i;
   const char *zParm;
@@ -682,7 +681,7 @@
   if( zParm==0 ) return;
 
   for(i=0; i<g.nAux && g.azAuxName[i]; i++){
-    if( sqlite3StrICmp(zParm,g.azAuxName[i])==0 ){
+    if( strcasecmp(zParm,g.azAuxName[i])==0 ){
       if( g.azAuxVal[i] ){
         sqlite3_result_text(context, g.azAuxVal[i], -1, SQLITE_STATIC);
       }
@@ -712,7 +711,6 @@
 ** currently selected value.  Results may be a single value column or
 ** two value,description columns.  The first result row is the default.
 */
-extern int sqlite3StrICmp(const char*, const char*);
 static void f_option(sqlite3_context *context, int argc, sqlite3_value **argv){
   const char *zParm;
   int i;
@@ -722,7 +720,7 @@
   if( zParm==0 ) return;
 
   for(i=0; i<g.nAux && g.azAuxName[i]; i++){
-    if( sqlite3StrICmp(zParm,g.azAuxName[i])==0 ){
+    if( strcasecmp(zParm,g.azAuxName[i])==0 ){
       if( g.azAuxVal[i] ){
         sqlite3_result_text(context, g.azAuxVal[i], -1, SQLITE_STATIC);
       }
