https://gitlab.freedesktop.org/dbus/dbus/-/merge_requests/526

--- dbus/dbus-transport-socket.c.orig	2025-02-27 16:29:06 UTC
+++ dbus/dbus-transport-socket.c
@@ -1208,8 +1208,8 @@ socket_do_iteration (DBusTransport *transport,
             do_io_error (transport);
           else
             {
-              dbus_bool_t need_read = (poll_fd.revents & _DBUS_POLLIN) > 0;
-              dbus_bool_t need_write = (poll_fd.revents & _DBUS_POLLOUT) > 0;
+              dbus_bool_t need_read = (poll_fd.revents & (_DBUS_POLLIN | _DBUS_POLLHUP)) > 0;
+              dbus_bool_t need_write = (poll_fd.revents & (_DBUS_POLLOUT | _DBUS_POLLHUP)) > 0;
 	      dbus_bool_t authentication_completed;
 
               _dbus_verbose ("in iteration, need_read=%d need_write=%d\n",
