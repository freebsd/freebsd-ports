--- src/oobs-user.c.orig	Fri Sep 15 19:16:41 2006
+++ src/oobs-user.c	Tue Oct 31 23:12:29 2006
@@ -18,6 +18,10 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
+#endif
+
 #include <glib-object.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -30,7 +34,9 @@
 #include "oobs-group.h"
 #include "oobs-defines.h"
 #include "utils.h"
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
 
 #define OOBS_USER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), OOBS_TYPE_USER, OobsUserPrivate))
 
