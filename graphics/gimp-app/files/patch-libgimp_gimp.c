Why is this patch needed?

--- libgimp/gimp.c.orig	2023-11-05 23:49:05 UTC
+++ libgimp/gimp.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <floatingpoint.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -450,6 +451,9 @@ gimp_main (const GimpPlugInInfo *info,
   gimp_env_init (TRUE);
 
   progname = argv[ARG_PROGNAME];
+
+  /* Ignore floating point exceptions */
+  fpsetmask(0);
 
   basename = g_path_get_basename (progname);
 
