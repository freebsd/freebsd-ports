--- incr/callback.c.orig	Tue May 30 21:19:18 2000
+++ incr/callback.c	Wed Nov  7 17:48:02 2001
@@ -1,7 +1,7 @@
 /* Common callback management for incremental layout engines. */
 
-#include <engine.h>
 #include <math.h>
+#include <engine.h>
 
 static ilbool do_node_cb(engview_t *view, Agraph_t *set, ILevf_t fn)
 {
