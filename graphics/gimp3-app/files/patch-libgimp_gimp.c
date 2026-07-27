--- libgimp/gimp.c.orig	2026-04-17 08:37:38 UTC
+++ libgimp/gimp.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <fenv.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -408,6 +409,9 @@ gimp_main (GType  plug_in_type,
   gimp_env_init (TRUE);
 
   progname = argv[ARG_PROGNAME];
+
+  /* Ignore floating point exceptions */
+  fedisableexcept(FE_ALL_EXCEPT);
 
   basename = g_path_get_basename (progname);
 
