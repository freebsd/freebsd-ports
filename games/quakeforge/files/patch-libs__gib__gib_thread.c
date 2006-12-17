--- ./libs/gib/gib_thread.c.orig	Thu Sep 11 03:03:10 2003
+++ ./libs/gib/gib_thread.c	Sun Dec 17 15:57:31 2006
@@ -89,7 +89,7 @@
 void
 GIB_Thread_Execute (void)
 {
-	static qboolean iterator (cbuf_t *cbuf, llist_node_t *node)
+	qboolean iterator (cbuf_t *cbuf, llist_node_t *node)
 	{
 		if (GIB_DATA(cbuf)->program)
 			Cbuf_Execute_Stack (cbuf);
