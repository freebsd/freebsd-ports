--- rusnet/rusnet_codepages.c.orig	2007-11-14 03:11:10.000000000 +0600
+++ rusnet/rusnet_codepages.c	2007-11-14 03:11:19.000000000 +0600
@@ -79,7 +79,7 @@
 	  
           MyFree(temp->incoming);
           MyFree(temp->outgoing);
-          MyFree((void *)temp);
+          MyFree(temp);
     }
 
     translator_list = NULL;
