--- oobs/oobs-user.c.orig	2007-10-30 09:16:53.406333206 -0400
+++ oobs/oobs-user.c	2007-10-30 09:40:02.560797530 -0400
@@ -18,12 +18,18 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
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
 #include <utmp.h>
 
 #include "oobs-usersconfig.h"
@@ -852,6 +858,7 @@
 
   login = oobs_user_get_login_name (user);
 
+#if 0 /* FreeBSD does not have ut_type in utmp */
   while (!match && (entry = getutent ()) != NULL)
     {
       match = (entry->ut_type == USER_PROCESS &&
@@ -862,4 +869,5 @@
   endutent ();
 
   return match;
+#endif
 }
