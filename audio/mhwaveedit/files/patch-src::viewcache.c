--- src/viewcache.c.orig	Wed Jun  4 15:23:06 2003
+++ src/viewcache.c	Wed Jun  4 15:23:45 2003
@@ -24,6 +24,11 @@
 #include "inifile.h"
 #include "main.h"
 
+#ifndef HAVE_CEILL
+#  define ceill(x) ceil((double)(x))
+#  define HAVE_CEILL
+#endif
+
 /* How many columns to update (max) for each call to view_cache_update */
 #define PIXELS_PER_UPDATE 10
 #define GUINT32(x) ((guint32)x)
