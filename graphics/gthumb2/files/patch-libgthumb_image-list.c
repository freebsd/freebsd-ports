--- libgthumb/image-list.c.orig	Sun Aug 18 00:36:36 2002
+++ libgthumb/image-list.c	Sun Aug 18 00:36:47 2002
@@ -46,6 +46,7 @@
 #include <config.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtkadjustment.h>
 #include <gtk/gtksignal.h>
