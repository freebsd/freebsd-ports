--- dbus/dbus-sysdeps-util-unix.c.orig	2022-09-14 12:12:21 UTC
+++ dbus/dbus-sysdeps-util-unix.c
@@ -44,6 +44,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
@@ -1394,7 +1395,7 @@ out:
  * On UNIX this should be the standard xdg freedesktop.org data directories:
  *
  * XDG_DATA_HOME=${XDG_DATA_HOME-$HOME/.local/share}
- * XDG_DATA_DIRS=${XDG_DATA_DIRS-/usr/local/share:/usr/share}
+ * XDG_DATA_DIRS=${XDG_DATA_DIRS-%%LOCALBASE%%/share:/usr/share}
  *
  * and
  *
@@ -1451,7 +1452,7 @@ _dbus_get_standard_session_servicedirs (DBusList **dir
     }
   else
     {
-      if (!_dbus_string_append (&servicedir_path, "/usr/local/share:/usr/share:"))
+      if (!_dbus_string_append (&servicedir_path, "%%LOCALBASE%%/share:/usr/share:"))
         goto oom;
     }
 
@@ -1484,7 +1485,7 @@ _dbus_get_standard_session_servicedirs (DBusList **dir
  *
  * On UNIX this should be the standard xdg freedesktop.org data directories:
  *
- * XDG_DATA_DIRS=${XDG_DATA_DIRS-/usr/local/share:/usr/share}
+ * XDG_DATA_DIRS=${XDG_DATA_DIRS-%%LOCALBASE%%/share:/usr/share}
  *
  * and
  *
@@ -1509,7 +1510,7 @@ _dbus_get_standard_system_servicedirs (DBusList **dirs
    * be available.
    */
   static const char standard_search_path[] =
-    "/usr/local/share:"
+    "%%LOCALBASE%%/share:"
     "/usr/share:"
     DBUS_DATADIR ":"
     "/lib";
