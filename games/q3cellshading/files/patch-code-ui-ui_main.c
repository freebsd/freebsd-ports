--- ./code/ui/ui_main.c.orig	Wed May 31 18:55:11 2006
+++ ./code/ui/ui_main.c	Wed May 31 19:10:12 2006
@@ -4988,7 +4988,7 @@
 		{
 			filelen = strlen(fileptr);
 
-			COM_StripExtension(fileptr,skinname);
+			COM_StripExtension(fileptr, skinname, sizeof(skinname));
 
 			// look for icon_????
 			if (Q_stricmpn(skinname, "icon_", 5) == 0 && !(Q_stricmp(skinname,"icon_blue") == 0 || Q_stricmp(skinname,"icon_red") == 0))
