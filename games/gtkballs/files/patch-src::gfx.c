--- src/gfx.c.orig	Thu Jan 22 02:17:31 2004
+++ src/gfx.c	Fri Jan 23 12:57:47 2004
@@ -7,6 +7,7 @@
  */
 #include <gtk/gtk.h>
 #include <sys/types.h>
+#include <sys/time.h>
 
 #include "gtkballs.h"
 #include "scoreboard.h" /* read_score */
