--- gnome-initial-setup/pages/account/um-utils.c.orig	2014-03-10 04:47:29.000000000 +0000
+++ gnome-initial-setup/pages/account/um-utils.c	2014-05-13 20:51:04.098992354 +0000
@@ -26,7 +26,8 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
+#include <utmpx.h>
+#define UT_NAMESIZE 16
 
 #include <glib.h>
 #include <glib/gi18n.h>
