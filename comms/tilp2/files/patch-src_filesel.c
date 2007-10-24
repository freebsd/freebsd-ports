--- src/filesel.c.orig	2007-10-24 09:06:41.542878494 -0400
+++ src/filesel.c	2007-10-24 09:06:56.125704803 -0400
@@ -36,6 +36,7 @@
 #  include <config.h>
 #endif				/*  */
 
+#undef GTK_DISABLE_DEPRECATED
 #include <stdio.h>
 #include <stdlib.h>
 #include <gtk/gtk.h>
