--- src/plugins/out-daap.c   2007-10-13 15:10:06.000000000 -0700
+++ src/plugins/out-daap.c.new        2011-10-16 18:08:53.207764000 -0700
@@ -1392,11 +1393,9 @@

     size = sizeof(servername);
     pi_server_name(servername,&size);
-    //    supports_update = conf_get_int("daap","supports_update",1);
+    supports_update = pi_conf_get_int("daap","supports_update",1);

     actual_length=139 + (int) strlen(servername);
-    if(!supports_update)
-        actual_length -= 9;

     if(actual_length > sizeof(server_info)) {
         pi_log(E_FATAL,"Server name too long.\n");
@@ -1434,6 +1433,8 @@
     current += dmap_add_int(current,"msdc",1);          /* 12 */

     if(supports_update)
+        current += dmap_add_char(current,"msup",1);         /* 9 */
+    else
         current += dmap_add_char(current,"msup",0);         /* 9 */

     out_daap_output_start(pwsc,ppi,actual_length);
