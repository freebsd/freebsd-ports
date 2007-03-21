--- bus/bus.c.orig	Wed Mar 21 16:20:57 2007
+++ bus/bus.c	Wed Mar 21 16:22:08 2007
@@ -21,6 +21,7 @@
  *
  */
 
+#include <signal.h>
 #include "bus.h"
 #include "activation.h"
 #include "connection.h"
@@ -731,14 +732,18 @@ bus_context_new (const DBusString *confi
         }
 
       bytes = _dbus_string_get_length (&pid);
-      if (_dbus_write_socket (print_pid_fd, &pid, 0, bytes) != bytes)
+      signal (SIGPIPE, SIG_IGN);
+      if (_dbus_write_socket (print_pid_fd, &pid, 0, bytes) != bytes &&
+          errno != EPIPE)
         {
           dbus_set_error (error, DBUS_ERROR_FAILED,
                           "Printing message bus PID: %s\n",
                           _dbus_strerror (errno));
           _dbus_string_free (&pid);
+	  signal (SIGPIPE, SIG_DFL);
           goto failed;
         }
+      signal (SIGPIPE, SIG_DFL);
 
       if (print_pid_fd > 2)
         _dbus_close_socket (print_pid_fd, NULL);
