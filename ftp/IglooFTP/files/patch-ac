--- main.c.orig	Thu Apr 15 20:05:15 1999
+++ main.c	Mon May  3 13:42:28 1999
@@ -20,6 +20,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <floatingpoint.h>
+#endif
 #include "protos.h"
 
 
@@ -101,6 +104,10 @@
   GtkWidget *vbox1;
   char IS_SPAWNED = FALSE;
   register int f;
+
+#ifdef __FreeBSD__
+  fpsetmask(0);
+#endif
 
   gtk_set_locale ();
   gtk_init (&argc, &argv);
