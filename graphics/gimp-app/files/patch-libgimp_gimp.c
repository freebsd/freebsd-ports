--- libgimp/gimp.c.orig	Fri Sep  1 06:14:32 2006
+++ libgimp/gimp.c	Sun Dec 31 15:56:37 2006
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <floatingpoint.h>
 
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
@@ -291,6 +292,9 @@
   gimp_env_init (TRUE);
 
   progname = argv[0];
+
+  /* Ignore floating point exceptions */
+  fpsetmask(0);
 
   basename = g_path_get_basename (progname);
 
