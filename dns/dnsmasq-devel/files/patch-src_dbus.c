--- src/dbus.c.orig	2025-04-18 13:01:14 UTC
+++ src/dbus.c
@@ -768,10 +768,10 @@ static DBusMessage *dbus_get_server_metrics(DBusMessag
 	add_dict_entry(&dict_array, "address", daemon->namebuff);
 	
 	add_dict_int(&dict_array, "port", port);
-	add_dict_int(&dict_array, "queries", serv->queries);
-	add_dict_int(&dict_array, "failed_queries", serv->failed_queries);
-	add_dict_int(&dict_array, "nxdomain", serv->nxdomain_replies);
-	add_dict_int(&dict_array, "retries", serv->retrys);
+	add_dict_int(&dict_array, "queries", queries);
+	add_dict_int(&dict_array, "failed_queries", failed_queries);
+	add_dict_int(&dict_array, "nxdomain", nxdomain_replies);
+	add_dict_int(&dict_array, "retries", retrys);
 	add_dict_int(&dict_array, "latency", sigma_latency/count_latency);
 	
 	dbus_message_iter_close_container(&server_array, &dict_array);
