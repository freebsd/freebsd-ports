--- code/server/sv_client.c.orig	Thu Jun  1 14:50:21 2006
+++ code/server/sv_client.c	Thu Jun  1 15:19:29 2006
@@ -756,24 +756,54 @@
 	int curindex;
 	int rate;
 	int blockspersnap;
-	int idPack, missionPack;
+	int idPack, missionPack, unreferenced = 1;
 	char errorMessage[1024];
+	char pakbuf[MAX_OSPATH], *pakptr;
+	const char *referencedPaks;
+	int numRefPaks;
 
 	if (!*cl->downloadName)
 		return;	// Nothing being downloaded
 
 	if (!cl->download) {
-		// We open the file here
+		// Chop off filename extension.
+		Com_sprintf(pakbuf, sizeof(pakbuf), "%s", cl->downloadName);
+		pakptr = Q_strrchr(pakbuf, '.');
 
-		Com_Printf( "clientDownload: %d : begining \"%s\"\n", cl - svs.clients, cl->downloadName );
+		if (pakptr) {
+			*pakptr = '\0';
 
-		missionPack = FS_idPak(cl->downloadName, "missionpack");
-		idPack = missionPack || FS_idPak(cl->downloadName, "baseq3");
+			// Check for pk3 filename extension
+			if (!Q_stricmp(pakptr + 1, "pk3")) {
+				referencedPaks = FS_ReferencedPakNames();
 
-		if ( !sv_allowDownload->integer || idPack ||
+				// Check whether the file appears in the list of referenced
+				// paks to prevent downloading of arbitrary files.
+				Cmd_TokenizeString(referencedPaks);
+				numRefPaks = Cmd_Argc();
+
+				for (curindex = 0; curindex < numRefPaks; curindex++) {
+					if (!FS_FilenameCompare(Cmd_Argv(curindex), pakbuf)) {
+						unreferenced = 0;
+
+						// now that we know the file is referenced,
+						// check whether it's legal to download it.
+						missionPack = FS_idPak(pakbuf, "missionpack");
+						idPack = missionPack || FS_idPak(pakbuf, BASEGAME);
+
+						break;
+					}
+				}
+			}
+		}
+
+		// We open the file here
+		if ( !sv_allowDownload->integer || idPack || unreferenced ||
 			( cl->downloadSize = FS_SV_FOpenFileRead( cl->downloadName, &cl->download ) ) <= 0 ) {
 			// cannot auto-download file
-			if (idPack) {
+			if (unreferenced) {
+				Com_sprintf(errorMessage, sizeof(errorMessage), "File \"%s\" is not referenced and cannot be downloaded.", cl->downloadName);
+			} else if (idPack) {
 				Com_Printf("clientDownload: %d : \"%s\" cannot download id pk3 files\n", cl - svs.clients, cl->downloadName);
 				if (missionPack) {
 					Com_sprintf(errorMessage, sizeof(errorMessage), "Cannot autodownload Team Arena file \"%s\"\n"
@@ -809,6 +839,8 @@
 			return;
 		}
  
+		Com_Printf( "clientDownload: %d : beginning \"%s\"\n", cl - svs.clients, cl->downloadName );
+
 		// Init
 		cl->downloadCurrentBlock = cl->downloadClientBlock = cl->downloadXmitBlock = 0;
 		cl->downloadCount = 0;
