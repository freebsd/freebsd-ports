--- server/gam_node.c.orig	2007-07-04 15:36:49.000000000 +0200
+++ server/gam_node.c	2011-09-17 11:19:10.000000000 +0200
@@ -23,6 +23,7 @@
 #include "gam_event.h"
 #include "gam_node.h"
 #include "gam_error.h"
+#include "gam_server.h"
 
 /**
  * Create a new node
@@ -122,7 +123,7 @@ gam_node_set_is_dir(GamNode * node, gboo
  * it has finished with the string.  If it must keep it longer, it
  * should makes its own copy.  The returned string must not be freed.
  */
-G_CONST_RETURN char *
+const char *
 gam_node_get_path(GamNode * node)
 {
     g_assert(node);
