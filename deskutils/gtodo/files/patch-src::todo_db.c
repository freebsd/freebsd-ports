--- src/todo_db.c.orig	Mon Sep 29 10:35:31 2003
+++ src/todo_db.c	Mon Sep 29 10:35:35 2003
@@ -401,8 +401,8 @@
 					item = g_ascii_strtoull(due, NULL,0);
 					if(atoi(done) &&  item < (now-settings.purge_days))
 					    {
-					    xmlFreeNode(cur1);
 					    xmlUnlinkNode(cur1);
+					    xmlFreeNode(cur1);
 					    cur1= root->xmlChildrenNode;
 					    if(cur1 != NULL) cur2= cur1->xmlChildrenNode;
 					    else cur2 = NULL;
