--- ./view.c.orig	2007-01-27 18:29:39.000000000 -0500
+++ ./view.c	2009-11-09 17:15:57.000000000 -0500
@@ -219,8 +219,6 @@
 ** pointer to an error message string (obtained from malloc) if
 ** there is a problem.
 */
-extern int sqlite3StrNICmp(const char*,const char*,int);
-extern int sqlite3StrICmp(const char*,const char*);
 char *verify_sql_statement(char *zSql){
   int i;
 
@@ -228,7 +226,7 @@
   ** the first token is "SELECT" and that there are no unquoted semicolons.
   */
   for(i=0; isspace(zSql[i]); i++){}
-  if( sqlite3StrNICmp(&zSql[i],"select",6)!=0 ){
+  if( sqlite3_strnicmp(&zSql[i],"select",6)!=0 ){
     return mprintf("The SQL must be a SELECT statement");
   }
   for(i=0; zSql[i]; i++){
