--- ./game/acesrc/acebot_nodes.c.orig	Fri Mar 23 23:28:55 2007
+++ ./game/acesrc/acebot_nodes.c	Sat Jul 21 09:32:49 2007
@@ -726,11 +726,7 @@
 
 	safe_bprintf(PRINT_MEDIUM,"Saving node table...");
 
-#ifdef __linux__
-	strcpy(filename,"botinfo/nav/");
-#else
-	strcpy(filename,"botinfo\\nav\\");
-#endif
+	strcpy(filename,BOTDIR"/botinfo/nav/");
 	strcat(filename,level.mapname);
 	strcat(filename,".nod");
 
