--- library/rb-node.c.orig	Sun Feb  9 03:12:01 2003
+++ library/rb-node.c	Mon Apr 21 20:27:45 2003
@@ -852,7 +861,7 @@
 			   int property_id)
 {
 	GValue *ret;
-	long mtime;
+	time_t mtime;
 	char *retval;
 	
 	g_return_val_if_fail (RB_IS_NODE (node), NULL);
