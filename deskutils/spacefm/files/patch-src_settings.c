--- src/settings.c.orig	2023-02-20 22:03:12 UTC
+++ src/settings.c
@@ -21,6 +21,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include "glib-utils.h" /* for g_mkdir_with_parents() */
 #include <glib/gi18n.h>
