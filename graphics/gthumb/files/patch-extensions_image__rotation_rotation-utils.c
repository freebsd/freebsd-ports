--- extensions/image_rotation/rotation-utils.c.orig	2025-09-16 07:18:36 UTC
+++ extensions/image_rotation/rotation-utils.c
@@ -20,6 +20,7 @@
  */
 
 #include <config.h>
+#include <stdbool.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <glib/gi18n.h>
