--- dbus/dbus-sysdeps-util-unix.c.orig	2019-06-09 12:08:49 UTC
+++ dbus/dbus-sysdeps-util-unix.c
@@ -42,6 +42,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <syslog.h>
 #include <sys/stat.h>
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
@@ -1367,7 +1368,7 @@ out:
  * On UNIX this should be the standard xdg freedesktop.org data directories:
  *
  * XDG_DATA_HOME=${XDG_DATA_HOME-$HOME/.local/share}
- * XDG_DATA_DIRS=${XDG_DATA_DIRS-/usr/local/share:/usr/share}
+ * XDG_DATA_DIRS=${XDG_DATA_DIRS-%%LOCALBASE%%/share:/usr/share}
  *
  * and
  *
@@ -1424,7 +1425,7 @@ _dbus_get_standard_session_servicedirs (DBusList **dir
     }
   else
     {
-      if (!_dbus_string_append (&servicedir_path, "/usr/local/share:/usr/share:"))
+      if (!_dbus_string_append (&servicedir_path, "%%LOCALBASE%%/share:/usr/share:"))
         goto oom;
     }
 
@@ -1457,7 +1458,7 @@ _dbus_get_standard_session_servicedirs (DBusList **dir
  *
  * On UNIX this should be the standard xdg freedesktop.org data directories:
  *
- * XDG_DATA_DIRS=${XDG_DATA_DIRS-/usr/local/share:/usr/share}
+ * XDG_DATA_DIRS=${XDG_DATA_DIRS-%%LOCALBASE%%/share:/usr/share}
  *
  * and
  *
@@ -1482,7 +1483,7 @@ _dbus_get_standard_system_servicedirs (DBusList **dirs
    * be available.
    */
   static const char standard_search_path[] =
-    "/usr/local/share:"
+    "%%LOCALBASE%%/share:"
     "/usr/share:"
     DBUS_DATADIR ":"
     "/lib";
