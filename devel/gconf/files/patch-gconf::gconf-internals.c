--- gconf/gconf-internals.c.orig	Mon Sep 29 22:35:14 2003
+++ gconf/gconf-internals.c	Mon Sep 29 22:35:16 2003
@@ -28,6 +28,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
@@ -2948,7 +2951,21 @@
 char*
 gconf_get_daemon_dir (void)
 {
-  return g_strconcat (g_get_home_dir (), "/.gconfd", NULL);
+  if (gconf_use_local_locks ())
+    {
+      char *s;
+      char *subdir;
+
+      subdir = g_strconcat ("gconfd-", g_get_user_name (), NULL);
+
+      s = g_strconcat (g_get_tmp_dir (), G_DIR_SEPARATOR_S, subdir, NULL);
+
+      g_free (subdir);
+
+      return s;
+    }
+  else
+    return g_strconcat (g_get_home_dir (), "/.gconfd", NULL);
 }
 
 char*
@@ -3040,6 +3057,8 @@
 
       if (gconf_file_exists (GCONF_BINDIR"/gconfd-2"))
         argv[0] = g_strconcat (GCONF_BINDIR, "/gconfd-2", NULL);
+      else if (gconf_file_exists (GCONF_PREFIX"/libexec/gconfd-2"))
+	argv[0] = g_strconcat (GCONF_PREFIX, "/libexec/gconfd-2", NULL);
       else
         argv[0] = g_strconcat (GCONF_BINDIR, "/" GCONFD, NULL);
 
@@ -4357,4 +4376,24 @@
     return FALSE;
   else
     return TRUE;
+}
+
+enum { UNKNOWN, LOCAL, NORMAL };
+
+gboolean
+gconf_use_local_locks (void)
+{
+  static int local_locks = UNKNOWN;
+
+  if (local_locks == UNKNOWN)
+    {
+      const char *l = 
+        g_getenv ("GCONF_GLOBAL_LOCKS");
+      
+      if (l && atoi (l) == 1)
+	local_locks = NORMAL;
+      else
+	local_locks = LOCAL;
+    }
+  return local_locks == LOCAL;
 }
