--- ./code/ui/ui_main.c.orig	Wed May 31 20:52:08 2006
+++ ./code/ui/ui_main.c	Wed May 31 20:56:29 2006
@@ -4971,7 +4971,7 @@
 		{
 			filelen = strlen(fileptr);
 
-			COM_StripExtension(fileptr,skinname);
+			COM_StripExtension(fileptr, skinname, sizeof(skinname));
 
 			// look for icon_????
 			if (Q_stricmpn(skinname, "icon_", 5) == 0 && !(Q_stricmp(skinname,"icon_blue") == 0 || Q_stricmp(skinname,"icon_red") == 0))
