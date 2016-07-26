--- src/plugins/out-daap.c.orig	2007-10-13 22:10:06 UTC
+++ src/plugins/out-daap.c
@@ -1392,11 +1392,9 @@ void out_daap_server_info(WS_CONNINFO *p
 
     size = sizeof(servername);
     pi_server_name(servername,&size);
-    //    supports_update = conf_get_int("daap","supports_update",1);
+    supports_update = pi_conf_get_int("daap","supports_update",1);
 
     actual_length=139 + (int) strlen(servername);
-    if(!supports_update)
-        actual_length -= 9;
 
     if(actual_length > sizeof(server_info)) {
         pi_log(E_FATAL,"Server name too long.\n");
@@ -1434,6 +1432,8 @@ void out_daap_server_info(WS_CONNINFO *p
     current += dmap_add_int(current,"msdc",1);          /* 12 */
 
     if(supports_update)
+        current += dmap_add_char(current,"msup",1);         /* 9 */
+    else
         current += dmap_add_char(current,"msup",0);         /* 9 */
 
     out_daap_output_start(pwsc,ppi,actual_length);
