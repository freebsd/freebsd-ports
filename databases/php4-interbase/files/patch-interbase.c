--- interbase.c	2007/01/17 23:59:07	1.91.2.34.2.4
+++ interbase.c	2007/02/16 07:11:33	1.91.2.34.2.5
@@ -3048,9 +3048,9 @@
 */
 
 	/* Build buffer for isc_service_attach() */
-	snprintf(buf, sizeof(buf), "%c%c%c%d%s%c%d%s", isc_spb_version, isc_spb_current_version, isc_spb_user_name, 
+	snprintf(spb_buffer, sizeof(spb_buffer), "%c%c%c%d%s%c%d%s", isc_spb_version, isc_spb_current_version, isc_spb_user_name, 
 						strlen(dba_user_name), dba_user_name, isc_spb_password, strlen(dba_password), dba_password);
-	spb_length = strlen(buf);
+	spb_length = strlen(spb_buffer);
 
 	/* Attach to the Service Manager */
 	snprintf(service_name, sizeof(service_name), "%s:service_mgr", ib_server);
