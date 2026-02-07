--- generic/mysqltcl.c.orig	2012-10-24 20:26:34 UTC
+++ generic/mysqltcl.c
@@ -46,6 +46,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
+#include <stdbool.h>
 
 #define MYSQL_SMALL_SIZE  TCL_RESULT_SIZE /* Smaller buffer size. */
 #define MYSQL_NAME_LEN     80    /* Max. database name length. */
@@ -911,7 +912,7 @@ static int Mysqltcl_Connect(ClientData clientData, Tcl
 #if (MYSQL_VERSION_ID>=32350)
   if(mysql_options_reconnect)
   {
-      my_bool reconnect = 1;
+      bool reconnect = 1;
       mysql_options(handle->connection, MYSQL_OPT_RECONNECT, &reconnect);
   }
   mysql_options(handle->connection,MYSQL_READ_DEFAULT_GROUP,groupname);
