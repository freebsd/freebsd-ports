--- src/mcategory.c.orig	Mon Sep 29 10:33:31 2003
+++ src/mcategory.c	Mon Sep 29 10:33:54 2003
@@ -98,8 +98,8 @@
 	    if(xmlStrEqual(temp, (const xmlChar *)category))
  		{
 		g_signal_handler_block(mw.option, shand);
-		xmlFreeNode(cur);
 		xmlUnlinkNode(cur);
+		xmlFreeNode(cur);
 		read_categorys();
 		g_signal_handler_unblock(mw.option, shand);
 		cur = NULL;
