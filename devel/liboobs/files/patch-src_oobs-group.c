--- src/oobs-group.c.orig	Fri Sep 15 18:41:04 2006
+++ src/oobs-group.c	Tue Oct 31 23:12:40 2006
@@ -18,7 +18,12 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
+#endif
+
 #include <glib-object.h>
+#include <unistd.h>
 #include "oobs-session.h"
 #include "oobs-group.h"
 #include "oobs-user.h"
@@ -27,7 +32,9 @@
 #include "oobs-groupsconfig-private.h"
 #include "oobs-defines.h"
 #include "utils.h"
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
 
 #define OOBS_GROUP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), OOBS_TYPE_GROUP, OobsGroupPrivate))
 
