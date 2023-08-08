--- gnome-initial-setup/pages/account/um-utils.c.orig	2023-01-28 19:16:53.089174000 -0800
+++ gnome-initial-setup/pages/account/um-utils.c	2023-01-28 19:17:14.814366000 -0800
@@ -26,7 +26,6 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -61,7 +60,7 @@
                                            NULL);
 }
 
-#define MAXNAMELEN  (UT_NAMESIZE - 1)
+#define MAXNAMELEN  (31)
 
 static gboolean
 is_username_used (const gchar *username)
