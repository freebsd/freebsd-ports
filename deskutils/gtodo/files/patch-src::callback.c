--- src/callback.c.orig	Mon Sep 29 01:45:56 2003
+++ src/callback.c	Mon Sep 29 01:48:27 2003
@@ -26,8 +26,8 @@
 
     if(cur != root) 
 	{
-	xmlFreeNode(cur);
 	xmlUnlinkNode(cur);
+	xmlFreeNode(cur);
 	gtk_list_store_remove(mw.list, &iter);
 	}
     else{
@@ -167,8 +167,8 @@
 	    if(xmlStrEqual(temp, (const xmlChar *)tm))
  		{
 		g_signal_handler_block(mw.option, shand);
-		xmlFreeNode(cur);
 		xmlUnlinkNode(cur);
+		xmlFreeNode(cur);
 		read_categorys();
 		g_signal_handler_unblock(mw.option, shand);
 		cur = NULL;
@@ -302,8 +302,8 @@
     			cur = get_id_node(category, value);
 			if(cur != root) 
 				{
-				xmlFreeNode(cur);
 				xmlUnlinkNode(cur);
+				xmlFreeNode(cur);
 				//gtk_list_store_remove(mw.list, &nextiter);
 				}
     			else{
