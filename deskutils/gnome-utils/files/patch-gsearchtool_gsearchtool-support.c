--- gsearchtool/gsearchtool-support.c.orig	Thu Dec 23 19:13:28 2004
+++ gsearchtool/gsearchtool-support.c	Thu Dec 23 19:13:38 2004
@@ -30,6 +30,7 @@
 #endif
 
 #include <glib/gi18n.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <gdk/gdkx.h>
 #include <bonobo-activation/bonobo-activation.h>
