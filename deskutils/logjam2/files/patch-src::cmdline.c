--- src/cmdline.c.orig	Tue Feb 17 09:49:23 2004
+++ src/cmdline.c	Tue Feb 17 09:49:39 2004
@@ -4,6 +4,7 @@
  * vim: tabstop=4 shiftwidth=4 noexpandtab :
  */
 
+#include <sys/types.h>
 #include "config.h"
 
 #ifdef HAVE_GTK
