
$FreeBSD$

--- src/state.h.orig	Tue Sep 23 06:07:03 2003
+++ src/state.h	Sun Sep 28 16:47:03 2003
@@ -20,7 +20,9 @@
  * USA
  */
 
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+#  include <stdint.h>
+#endif
 
 int dcc_get_state_dir (char **p);
 int dcc_open_state_file (int *p_fd);
