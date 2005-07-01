--- bus/bus.c.orig	Thu Jun 30 23:55:41 2005
+++ bus/bus.c	Thu Jun 30 23:56:04 2005
@@ -486,7 +486,7 @@ process_config_every_time (BusContext   
 
   _dbus_list_foreach (bus_config_parser_get_conf_dirs (parser),
 		      (DBusForeachFunction) bus_watch_directory,
-		      NULL);
+		      bus_context_get_loop (context));
 
   _DBUS_ASSERT_ERROR_IS_CLEAR (error);
   retval = TRUE;
