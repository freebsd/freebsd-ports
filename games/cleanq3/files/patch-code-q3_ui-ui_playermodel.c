--- ./code/q3_ui/ui_playermodel.c.orig	Wed May 31 20:52:07 2006
+++ ./code/q3_ui/ui_playermodel.c	Wed May 31 20:54:50 2006
@@ -404,7 +404,7 @@
 		{
 			filelen = strlen(fileptr);
 
-			COM_StripExtension(fileptr,skinname);
+			COM_StripExtension(fileptr, skinname, sizeof(skinname));
 
 			// look for icon_????
 			if (!Q_stricmpn(skinname,"icon_",5))
