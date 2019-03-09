--- src/wwwsrv.c.orig	2018-12-23 19:04:36 UTC
+++ src/wwwsrv.c
@@ -100,12 +100,12 @@ lw_wwwsrv_init (LW_WWWSRV_DATA * data,
 
   data->privacy = privacy;
   data->log = log;
-  strncpy (data->metaserver, metaserver, URL_SIZE);
+  strncpy (data->metaserver, metaserver, sizeof(data->metaserver));
   data->port = port;
   data->busy_players = busy_players;
   data->max_players = max_players;
-  strncpy (data->password, password, PASSWORD_SIZE);
-  strncpy (data->comment, comment, COMMENT_SIZE);
+  strncpy (data->password, password, sizeof(data->password));
+  strncpy (data->comment, comment, sizeof(data->comment));
 }
 
 /*------------------------------------------------------------------*/
