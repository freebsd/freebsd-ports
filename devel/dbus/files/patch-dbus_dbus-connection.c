--- dbus/dbus-connection.c.orig	2025-02-27 16:29:06 UTC
+++ dbus/dbus-connection.c
@@ -2510,7 +2510,7 @@ _dbus_connection_block_pending_call (DBusPendingCall *
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (-1);
         }
       else
         {          
@@ -2519,7 +2519,7 @@ _dbus_connection_block_pending_call (DBusPendingCall *
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  -1);
         }
 
       goto recheck_status;
