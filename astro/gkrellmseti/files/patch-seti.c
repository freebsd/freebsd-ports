--- seti.c.orig	Sat Oct 20 16:24:45 2001
+++ seti.c	Sat Oct 20 16:25:59 2001
@@ -1106,10 +1106,10 @@
 	style_id = gkrellm_add_meter_style(&plugin_mon, STYLE_NAME);
 
 	g_free(client_info.seti_file_path) ;
-	client_info.seti_file_path = g_strdup("/opt/setiathome/") ;
+	client_info.seti_file_path = g_strdup("/var/db/setiathome/") ;
 
 	g_free(client_info.seti_client_path) ;
-	client_info.seti_client_path = g_strdup("/opt/setiathome/") ;
+	client_info.seti_client_path = g_strdup("/%%LOCALBASE%%/sbin/") ;
 
 	g_free(client_info.state_file) ;
 	client_info.state_file = g_strdup_printf("%s/state.sah", client_info.seti_file_path) ;
