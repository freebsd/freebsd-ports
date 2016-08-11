--- src/ghostess.c.orig	2012-01-06 06:11:54 UTC
+++ src/ghostess.c
@@ -57,6 +57,7 @@
 #include <dirent.h>
 #include <pthread.h>
 #include <math.h>
+#include <errno.h>
 
 #include <glib.h>
 #include <gtk/gtk.h>
