--- unix/runargv.c.orig	Mon May  1 18:38:28 2006
+++ unix/runargv.c	Mon May  1 18:38:58 2006
@@ -66,6 +66,9 @@
   with runargv().
 */
 
+#ifdef HAVE_CONFIG_H
+#  include "config.h"
+#endif
 #include <signal.h>
 
 #include "extern.h"
