--- gnome-initial-setup/pages/account/um-utils.c.orig	2025-03-14 10:45:52 UTC
+++ gnome-initial-setup/pages/account/um-utils.c
@@ -26,7 +26,6 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -61,7 +60,7 @@ clear_entry_validation_error (GtkEntry *entry)
                                            NULL);
 }
 
-#define MAXNAMELEN  (UT_NAMESIZE - 1)
+#define MAXNAMELEN  (31)
 
 static gboolean
 is_username_used (const gchar *username)
