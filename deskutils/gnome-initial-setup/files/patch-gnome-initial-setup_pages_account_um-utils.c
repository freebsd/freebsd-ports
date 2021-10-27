--- ./gnome-initial-setup/pages/account/um-utils.c.orig	2021-09-17 01:31:10.617948800 -0700
+++ ./gnome-initial-setup/pages/account/um-utils.c	2021-10-04 20:15:17.919413000 -0700
@@ -26,7 +26,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -159,7 +159,7 @@
         cairo_restore (cr);
 }
 
-#define MAXNAMELEN  (UT_NAMESIZE - 1)
+#define MAXNAMELEN  31
 
 static gboolean
 is_username_used (const gchar *username)
