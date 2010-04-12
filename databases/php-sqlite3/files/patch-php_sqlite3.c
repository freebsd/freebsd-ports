--- ./php_sqlite3.c.orig	2010-04-12 14:26:36.000000000 -0400
+++ ./php_sqlite3.c	2010-04-12 14:27:02.000000000 -0400
@@ -471,7 +471,7 @@
    * duplicate it (SQLITE_STATIC flag).
    */
      
-  z_val->refcount++;
+  Z_ADDREF_P(z_val);
   
   if (sqlite3_bind_text(stmt->stmt, idx, Z_STRVAL_P(z_val), Z_STRLEN_P(z_val), SQLITE_STATIC) != SQLITE_OK)
     RETURN_FALSE;
@@ -504,7 +504,7 @@
    * duplicate it (SQLITE_STATIC flag).
    */
    
-  z_val->refcount++;
+  Z_ADDREF_P(z_val);
   
   if (sqlite3_bind_blob(stmt->stmt, idx, Z_STRVAL_P(z_val), Z_STRLEN_P(z_val), SQLITE_STATIC) != SQLITE_OK)
     RETURN_FALSE;
