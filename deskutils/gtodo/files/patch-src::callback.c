--- src/callback.c.orig	Mon Sep 29 10:26:50 2003
+++ src/callback.c	Mon Sep 29 10:29:36 2003
@@ -26,8 +26,8 @@
 
     if(cur != root) 
 	{
-	xmlFreeNode(cur);
 	xmlUnlinkNode(cur);
+	xmlFreeNode(cur);
 	gtk_list_store_remove(mw.list, &iter);
 	}
     else{
@@ -166,8 +166,8 @@
 	    if(xmlStrEqual(temp, (const xmlChar *)tm))
  		{
 		g_signal_handler_block(mw.option, shand);
-		xmlFreeNode(cur);
 		xmlUnlinkNode(cur);
+		xmlFreeNode(cur);
 		read_categorys();
 		g_signal_handler_unblock(mw.option, shand);
 		cur = NULL;
@@ -301,8 +301,8 @@
     			cur = get_id_node(category, value);
 			if(cur != root) 
 				{
-				xmlFreeNode(cur);
 				xmlUnlinkNode(cur);
+				xmlFreeNode(cur);
 				}
     	    		else{
 				  g_print(_("item not found.. that can't be\n"));
