--- dbus/dbus-connection.c.orig	2010-08-31 21:44:19.000000000 +0000
+++ dbus/dbus-connection.c	2010-09-18 18:01:19.000000000 +0000
@@ -2364,7 +2364,7 @@ _dbus_connection_block_pending_call (DBu
   DBusConnection *connection;
   dbus_uint32_t client_serial;
   DBusTimeout *timeout;
-  int timeout_milliseconds, elapsed_milliseconds;
+  int timeout_milliseconds, elapsed_milliseconds, remain_milliseconds;
 
   _dbus_assert (pending != NULL);
 
@@ -2445,7 +2445,11 @@ _dbus_connection_block_pending_call (DBu
   _dbus_get_current_time (&tv_sec, &tv_usec);
   elapsed_milliseconds = (tv_sec - start_tv_sec) * 1000 +
 	  (tv_usec - start_tv_usec) / 1000;
-  
+  if (timeout_milliseconds != -1)
+    remain_milliseconds = timeout_milliseconds - elapsed_milliseconds;
+  else
+    remain_milliseconds = -1;
+
   if (!_dbus_connection_get_is_connected_unlocked (connection))
     {
       DBusMessage *error_msg;
@@ -2471,7 +2475,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2480,7 +2484,7 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
@@ -2489,7 +2493,7 @@ _dbus_connection_block_pending_call (DBu
     _dbus_verbose ("dbus_connection_send_with_reply_and_block(): clock set backward\n");
   else if (elapsed_milliseconds < timeout_milliseconds)
     {
-      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", timeout_milliseconds - elapsed_milliseconds);
+      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", remain_milliseconds);
       
       if (status == DBUS_DISPATCH_NEED_MEMORY)
         {
@@ -2499,7 +2503,7 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
-          _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
         }
       else
         {          
@@ -2508,7 +2512,7 @@ _dbus_connection_block_pending_call (DBu
                                                   NULL,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
-                                                  timeout_milliseconds - elapsed_milliseconds);
+                                                  remain_milliseconds);
         }
 
       goto recheck_status;
