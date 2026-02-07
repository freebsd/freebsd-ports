--- code/client/cl_parse.c.orig	2011-12-24 12:29:30 UTC
+++ code/client/cl_parse.c
@@ -534,6 +534,26 @@ void CL_ParseGamestate( msg_t *msg ) {
 	// reinitialize the filesystem if the game directory has changed
 	FS_ConditionalRestart( clc.checksumFeed );
 
+	if (dangerousPaksFound) {
+		char PakList[MAX_STRING_CHARS];
+		for (i = 0; i < dangerousPaksFound; i++) {
+			Q_strcat(PakList, sizeof(PakList), va("%s.pk3, ", dangerousPakNames[i]));
+		}
+
+		PakList[strlen(PakList) - 2] = 0;
+
+		Cvar_Set("com_errorMessage", va(
+			"^1WARNING! ^7Dangerous file(s) found in downloaded pk3%s:\n\n%s\n\n"
+			"You should go delete %s immediately. %s could lead to malicious code execution.",
+			dangerousPaksFound == 1 ? "" : "s",
+			PakList,
+			dangerousPaksFound == 1 ? "that file" : "those files",
+			dangerousPaksFound == 1 ? "It" : "They"));
+
+		VM_Call(uivm, UI_SET_ACTIVE_MENU, UIMENU_MAIN);
+		return;
+	}
+
 	// This used to call CL_StartHunkUsers, but now we enter the download state before loading the
 	// cgame
 	CL_InitDownloads();
@@ -624,7 +644,7 @@ void CL_ParseDownload ( msg_t *msg ) {
 			clc.download = 0;
 
 			// rename the file
-			FS_SV_Rename ( clc.downloadTempName, clc.downloadName );
+			FS_SV_Rename ( clc.downloadTempName, clc.downloadName, qfalse );
 		}
 
 		// send intentions now
