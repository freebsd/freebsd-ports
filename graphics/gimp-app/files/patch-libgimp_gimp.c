Why is this patch needed?

--- libgimp/gimp.c.orig	2018-03-25 14:35:18.000000000 +0200
+++ libgimp/gimp.c	2018-04-14 18:55:00.422346000 +0200
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <floatingpoint.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -425,6 +426,9 @@ gimp_main (const GimpPlugInInfo *info,
   gimp_env_init (TRUE);
 
   progname = argv[ARG_PROGNAME];
+
+  /* Ignore floating point exceptions */
+  fpsetmask(0);
 
   basename = g_path_get_basename (progname);
 
