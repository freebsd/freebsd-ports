--- dbus/dbus-sysdeps-util.c.orig	Sat Apr  2 15:29:28 2005
+++ dbus/dbus-sysdeps-util.c	Sat Apr  2 15:29:45 2005
@@ -142,7 +142,7 @@ _dbus_become_daemon (const DBusString *p
 	      return FALSE;
 	    }
 	  
-	  if (!_dbus_string_append_int (&pid, _dbus_getpid ()) ||
+	  if (!_dbus_string_append_int (&pid, child_pid) ||
 	      !_dbus_string_append (&pid, "\n"))
 	    {
 	      _dbus_string_free (&pid);
