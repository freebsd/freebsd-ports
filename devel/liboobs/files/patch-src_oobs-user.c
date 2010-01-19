--- oobs/oobs-user.c
+++ oobs/oobs-user.c
@@ -18,13 +18,28 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
+#endif
+
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
-#include <utmp.h>
+#endif
+#ifdef HAVE_UTMPX_H
+#include <utmpx.h>
+#endif
 
 #include "oobs-usersconfig.h"
 #include "oobs-user.h"
@@ -811,7 +826,8 @@
 gboolean
 oobs_user_get_active (OobsUser *user)
 {
-  struct utmp *entry;
+#ifdef HAVE_UTMPX_H
+  struct utmpx *entry;
   const gchar *login;
   gboolean match = FALSE;
 
@@ -819,14 +835,18 @@
 
   login = oobs_user_get_login_name (user);
 
-  while (!match && (entry = getutent ()) != NULL)
+  setutxent ();
+  while (!match && (entry = getutxent ()) != NULL)
     {
       match = (entry->ut_type == USER_PROCESS &&
 	       strcmp (entry->ut_user, login) == 0);
     }
 
   /* close utmp */
-  endutent ();
+  endutxent ();
 
   return match;
+#else
+  return FALSE;
+#endif
 }
