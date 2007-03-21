--- dbus/dbus-sysdeps-util-unix.c.orig	Mon Dec 11 14:21:10 2006
+++ dbus/dbus-sysdeps-util-unix.c	Wed Mar 21 16:22:45 2007
@@ -157,15 +157,19 @@ _dbus_become_daemon (const DBusString *p
 	    }
 	  
 	  bytes = _dbus_string_get_length (&pid);
-	  if (_dbus_write_socket (print_pid_fd, &pid, 0, bytes) != bytes)
+	  signal (SIGPIPE, SIG_IGN);
+	  if (_dbus_write_socket (print_pid_fd, &pid, 0, bytes) != bytes &&
+              errno != EPIPE)
 	    {
 	      dbus_set_error (error, DBUS_ERROR_FAILED,
 			      "Printing message bus PID: %s\n",
 			      _dbus_strerror (errno));
 	      _dbus_string_free (&pid);
               kill (child_pid, SIGTERM);
+	      signal (SIGPIPE, SIG_DFL);
 	      return FALSE;
 	    }
+	  signal (SIGPIPE, SIG_DFL);
 	  
 	  _dbus_string_free (&pid);
 	}
