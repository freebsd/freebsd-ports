--- oobs/oobs-user.c.orig	2010-01-31 17:36:52.000000000 +0000
+++ oobs/oobs-user.c	2010-01-31 17:40:21.000000000 +0000
@@ -19,13 +19,24 @@
  *          Milan Bouchet-Valat <nalimilan@club.fr>.
  */
 
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version >= 900007
+#  define HAVE_UTMPX_H
+# endif
+#endif
+
 #include <glib-object.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
+#ifdef HAVE_UTMPX_H
 #include <utmpx.h>
+#endif
 
 #include "oobs-object-private.h"
 #include "oobs-usersconfig.h"
@@ -1252,6 +1263,7 @@ oobs_user_set_locale (OobsUser *user, co
 gboolean
 oobs_user_get_active (OobsUser *user)
 {
+#ifdef HAVE_UTMPX_H
   struct utmpx *entry;
   const gchar *login;
   gboolean match = FALSE;
@@ -1272,6 +1284,9 @@ oobs_user_get_active (OobsUser *user)
   endutxent ();
 
   return match;
+#else
+  return FALSE;
+#endif
 }
 
 /**
