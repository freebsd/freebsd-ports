--- dbus/dbus-connection.c.orig	2010-03-13 17:21:40.000000000 -0500
+++ dbus/dbus-connection.c	2010-03-13 17:25:28.000000000 -0500
@@ -2280,7 +2280,7 @@ _dbus_connection_block_pending_call (DBu
   DBusConnection *connection;
   dbus_uint32_t client_serial;
   DBusTimeout *timeout;
-  int timeout_milliseconds, elapsed_milliseconds;
+  int timeout_milliseconds, elapsed_milliseconds, remain_milliseconds;
 
   _dbus_assert (pending != NULL);
 
@@ -2360,6 +2360,10 @@ _dbus_connection_block_pending_call (DBu
   _dbus_get_current_time (&tv_sec, &tv_usec);
   elapsed_milliseconds = (tv_sec - start_tv_sec) * 1000 +
 	  (tv_usec - start_tv_usec) / 1000;
+  if (timeout_milliseconds != -1)
+    remain_milliseconds = timeout_milliseconds - elapsed_milliseconds;
+  else
+    remain_milliseconds = -1;
   
   if (!_dbus_connection_get_is_connected_unlocked (connection))
     {
@@ -2386,7 +2390,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2394,7 +2398,7 @@ _dbus_connection_block_pending_call (DBu
           _dbus_connection_do_iteration_unlocked (connection,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
@@ -2403,7 +2407,7 @@ _dbus_connection_block_pending_call (DBu
     _dbus_verbose ("dbus_connection_send_with_reply_and_block(): clock set backward\n");
   else if (elapsed_milliseconds < timeout_milliseconds)
     {
-      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", timeout_milliseconds - elapsed_milliseconds);
+      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", remain_milliseconds);
       
       if (status == DBUS_DISPATCH_NEED_MEMORY)
         {
@@ -2413,7 +2417,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2421,7 +2425,7 @@ _dbus_connection_block_pending_call (DBu
           _dbus_connection_do_iteration_unlocked (connection,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
