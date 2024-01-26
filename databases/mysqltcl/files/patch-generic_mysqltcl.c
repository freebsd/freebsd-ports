--- generic/mysqltcl.c.orig	2024-01-26 14:58:40 UTC
+++ generic/mysqltcl.c
@@ -911,7 +911,7 @@ static int Mysqltcl_Connect(ClientData clientData, Tcl
 #if (MYSQL_VERSION_ID>=32350)
   if(mysql_options_reconnect)
   {
-      my_bool reconnect = 1;
+      bool reconnect = 1;
       mysql_options(handle->connection, MYSQL_OPT_RECONNECT, &reconnect);
   }
   mysql_options(handle->connection,MYSQL_READ_DEFAULT_GROUP,groupname);
