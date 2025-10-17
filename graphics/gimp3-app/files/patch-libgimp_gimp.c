--- libgimp/gimp.c.orig	2025-05-17 22:51:03 UTC
+++ libgimp/gimp.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <fenv.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -348,6 +349,9 @@ gimp_main (GType  plug_in_type,
   gimp_env_init (TRUE);
 
   progname = argv[ARG_PROGNAME];
+
+  /* Ignore floating point exceptions */
+  fedisableexcept(FE_ALL_EXCEPT);
 
   basename = g_path_get_basename (progname);
 
