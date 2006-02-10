--- main.c.orig	Thu Apr 15 19:05:15 1999
+++ main.c	Fri Feb 10 22:43:48 2006
@@ -20,6 +20,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <floatingpoint.h>
+#endif
 #include "protos.h"
 
 
@@ -100,7 +103,22 @@
   GtkWidget *hbox;
   GtkWidget *vbox1;
   char IS_SPAWNED = FALSE;
+  char *td;
   register int f;
+
+#ifdef __FreeBSD__
+  fpsetmask(0);
+#endif
+  if ((td = getenv("TMPDIR")) != NULL && strlen(td) != 0) {
+    if (td[strlen(td)-1] == '/')
+      strncpy(tmpfile_template, td, strlen(td)-1);
+    else
+      strncpy(tmpfile_template, td, strlen(td));
+  } else {
+    strcpy(tmpfile_template, "/tmp");
+  }
+  strncat(tmpfile_template, "/", sizeof(tmpfile_template));
+  strncat(tmpfile_template, TMPFILE_FILE, sizeof(tmpfile_template));
 
   gtk_set_locale ();
   gtk_init (&argc, &argv);
