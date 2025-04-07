--- libgimp/gimp.c.orig	2024-12-27 13:34:56 UTC
+++ libgimp/gimp.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <floatingpoint.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -341,6 +342,9 @@ gimp_main (GType  plug_in_type,
   gimp_env_init (TRUE);
 
   progname = argv[ARG_PROGNAME];
+
+  /* Ignore floating point exceptions */
+  fpsetmask(0);
 
   basename = g_path_get_basename (progname);
 
