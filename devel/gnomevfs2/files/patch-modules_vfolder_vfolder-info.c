--- modules/vfolder/vfolder-info.c.orig	Fri Nov 29 13:40:11 2002
+++ modules/vfolder/vfolder-info.c	Fri Nov 29 13:40:19 2002
@@ -1721,7 +1721,7 @@
 
 			for (i = 0; ppath[i] != NULL; i++) {
 				dir = g_build_filename (ppath[i], 
-							"/share/applications/",
+							"/share/gnome/applications/",
 							NULL);
 				id = itemdir_new (info, 
 						  dir, 
