--- src/mlview-service.c.orig	Sat Jul 23 12:10:16 2005
+++ src/mlview-service.c	Sat Jul 23 12:23:14 2005
@@ -282,23 +282,23 @@
 	service_name = g_strdup_printf ("%s.%s", 
 				        PRIVATE (a_this)->name,
 			                tab) ;
-	service_result = dbus_bus_acquire_service 
+	service_result = dbus_bus_request_name 
 		(dbus_connection,
 		 service_name, 0, &dbus_error) ;
 
 	switch (service_result) {
-		case DBUS_SERVICE_REPLY_PRIMARY_OWNER:
+		case DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER:
 			/*we started the service, OK*/
 			mlview_utils_trace_debug 
 				("Service name: %s registered\n",
 				 service_name) ;
 			status = register_dbus_objects (a_this) ;
 			break ;
-		case DBUS_SERVICE_REPLY_ALREADY_OWNER:
+		case DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER:
 			/*we were already started as service. OK still*/
 			status = MLVIEW_OK ;
 			break ;
-		case DBUS_SERVICE_REPLY_SERVICE_EXISTS:
+		case DBUS_REQUEST_NAME_REPLY_EXISTS:
 			/* 
 			 * an other process has been registered under
 			 * with the same service name. So we can't be registered
@@ -312,7 +312,7 @@
 					 "moment") ;
 			}
 			goto try_service_name ;
-		case DBUS_SERVICE_REPLY_IN_QUEUE:
+		case DBUS_REQUEST_NAME_REPLY_IN_QUEUE:
 			/*
 			 * our request is queued. (bus overcrowded ?) KO
 			 */
