--- server/gam_debug_lists.c.orig	Sat Jul 16 18:53:23 2005
+++ server/gam_debug_lists.c	Sat Jul 16 18:53:43 2005
@@ -28,6 +28,8 @@
 #include <string.h> /* for memset() debug */
 #include "glib.h"
 
+#ifdef GAM_DEBUG_ENABLED
+
 GList*
 g_list_alloc (void)
 {
@@ -252,4 +254,4 @@ g_list_length (GList *list)
   
   return length;
 }
-
+#endif /* GAM_DEBUG_ENABLED */
