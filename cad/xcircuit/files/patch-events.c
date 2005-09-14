--- events.c.orig	Thu Sep  8 22:33:01 2005
+++ events.c	Wed Sep 14 14:11:38 2005
@@ -2436,7 +2436,7 @@
 	    pathptr rotatepath = SELTOPATH(selectobj);
 
 	    register_for_undo(XCF_Edit, UNDO_MORE, areastruct.topinstance,
-			*rotatepath);
+			rotatepath);
 	    for (genpart = rotatepath->plist; genpart < rotatepath->plist
 		  + rotatepath->parts; genpart++)
 	       elemrotate(genpart, direction);
