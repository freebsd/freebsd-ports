--- ./qw/source/cl_chat.c.orig	Fri Jul 18 03:27:26 2003
+++ ./qw/source/cl_chat.c	Sun Dec 17 16:05:14 2006
@@ -66,7 +66,7 @@
 static void
 CL_Ignore_Sanity_Check (void)
 {
-	static qboolean iterator (ignore_t *ig, llist_node_t *node)
+	qboolean iterator (ignore_t *ig, llist_node_t *node)
 	{
 		if (cl.players[ig->slot].userid != ig->uid) // We got out of sync somehow
 			llist_remove (node);
@@ -80,12 +80,12 @@
 {
 	CL_Ignore_Sanity_Check ();
 	if (Cmd_Argc () == 1) {
-		static qboolean live_iterator (ignore_t *ig, llist_node_t *node)
+		qboolean live_iterator (ignore_t *ig, llist_node_t *node)
 		{
 			Sys_Printf ("%5i - %s\n", ig->uid, Info_ValueForKey (cl.players[ig->slot].userinfo, "name"));
 			return true;
 		}
-		static qboolean dead_iterator (ignore_t *ig, llist_node_t *node)
+		qboolean dead_iterator (ignore_t *ig, llist_node_t *node)
 		{
 			Sys_Printf ("%s\n", ig->lastname);
 			return true;
@@ -145,7 +145,7 @@
 	dstring_t *test = dstring_newstr ();
 	qboolean allowed = true;
 
-	static qboolean iterator (ignore_t *ig, llist_node_t *node)
+	qboolean iterator (ignore_t *ig, llist_node_t *node)
 	{
 		if (cl.players[ig->slot].userid != ig->uid) { // We got out of sync somehow
 			llist_remove (node);
@@ -183,7 +183,7 @@
 {
 	ignore_t *found = 0;
 
-	static qboolean iterator (ignore_t *ig, llist_node_t *node)
+	qboolean iterator (ignore_t *ig, llist_node_t *node)
 	{
 		if (!strcmp (ig->lastname, name)) {
 			found = ig;
