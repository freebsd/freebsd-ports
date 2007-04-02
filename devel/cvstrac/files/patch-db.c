--- db.c.org	Wed Dec 27 11:14:31 2006
+++ db.c	Wed Dec 27 11:15:09 2006
@@ -107,6 +107,8 @@
   extern int sqlite3StrICmp(const char*, const char*);
   if( type==SQLITE_SELECT ){
     return SQLITE_OK;
+  }else if( type==SQLITE_FUNCTION ){
+    return SQLITE_OK;
   }else if( type==SQLITE_READ ){
     if( sqlite3StrICmp(zArg1,"user")==0 ){
       if( sqlite3StrICmp(zArg2,"passwd")==0 || sqlite3StrICmp(zArg2,"email")==0 ){
