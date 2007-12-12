--- ref_gl/r_script.c.orig	Wed Dec 12 01:22:30 2007
+++ ref_gl/r_script.c	Wed Dec 12 01:21:49 2007
@@ -1020,35 +1020,16 @@
 	free(buf);
 }
 
-extern char **FS_ListFiles( char *, int *, unsigned, unsigned );
+extern char **FS_ListFiles2( char *, int *, unsigned, unsigned );
 extern void FS_FreeFileList (char **list, int n);
 void RS_ScanPathForScripts (void)
 {
 	char	script[MAX_OSPATH];
-	char	dirstring[1024], *c;
+	char	*c;
 	char	**script_list;
 	int	script_count, i;
-	char *path = NULL;
-
-
-	Com_sprintf(dirstring, sizeof(dirstring), "%s/scripts/*.rscript", FS_Gamedir());
-	script_list = FS_ListFiles(dirstring, &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
-
-	if(script_list) {
-		for (i = 0; i < script_count-1; i++)
-		{
-			c = COM_SkipPath(script_list[i]);
-			Com_sprintf(script, MAX_OSPATH, "scripts/%s", c);
-			RS_LoadScript(script);
-		}
-
-		FS_FreeFileList(script_list, script_count);
-	}
-
-	script_count = 0;
 
-	Com_sprintf(dirstring, sizeof(dirstring), "%s/scripts/*.rscript", BASEDIRNAME);
-	script_list = FS_ListFiles(dirstring, &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
+	script_list = FS_ListFiles2("scripts/*.rscript", &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
 
 	if(script_list) {
 		for (i = 0; i < script_count-1; i++)
@@ -1057,32 +1038,12 @@
 			Com_sprintf(script, MAX_OSPATH, "scripts/%s", c);
 			RS_LoadScript(script);
 		}
-
 		FS_FreeFileList(script_list, script_count);
 	}
 
 	script_count = 0;
 	if(gl_normalmaps->value) { //search for normal map scripts ONLY if we are using normal mapping
-		
-		Com_sprintf(dirstring, sizeof(dirstring), "%s/scripts/normals/*.rscript", FS_Gamedir());
-		script_list = FS_ListFiles(dirstring, &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
-
-		if(script_list) {
-			for (i = 0; i < script_count-1; i++)
-			{
-				c = COM_SkipPath(script_list[i]);
-				Com_sprintf(script, MAX_OSPATH, "scripts/normals/%s", c);
-				RS_LoadScript(script);
-			}
-
-			FS_FreeFileList(script_list, script_count);
-		}
-
-		script_count = 0;
-
-		Com_sprintf(dirstring, sizeof(dirstring), "%s/scripts/normals/*.rscript", BASEDIRNAME);
-		script_list = FS_ListFiles(dirstring, &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
-	
+		script_list = FS_ListFiles("scripts/normals/*.rscript", &script_count, 0, SFF_SUBDIR | SFF_HIDDEN | SFF_SYSTEM);
 		if(script_list) {
 			for (i = 0; i < script_count-1; i++)
 			{
@@ -1090,7 +1051,6 @@
 				Com_sprintf(script, MAX_OSPATH, "scripts/normals/%s", c);
 				RS_LoadScript(script);
 			}
-
 			FS_FreeFileList(script_list, script_count);
 		}
 	}
