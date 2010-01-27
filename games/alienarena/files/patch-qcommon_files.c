--- qcommon/files.c	2010-01-27 11:24:33.000000000 -0500
+++ qcommon/files.c	2010-01-27 11:26:40.000000000 -0500
@@ -568,7 +568,7 @@
 ================
 FS_AddHomeAsGameDirectory
 
-Use ~/.codered/dir as fs_gamedir
+Use ~/.config/alienarena/dir as fs_gamedir
 ================
 */
 void FS_AddHomeAsGameDirectory (char *dir)
@@ -586,7 +586,7 @@
 		homedir = getenv("HOME");
 		if (!homedir)
 			return;
-		len = snprintf(gdir,sizeof(gdir),"%s/.codered/%s/", homedir, dir);
+		len = snprintf(gdir,sizeof(gdir),"%s/.config/alienarena/%s/", homedir, dir);
 	}
 
 	Com_Printf("using %s for writing\n",gdir);
