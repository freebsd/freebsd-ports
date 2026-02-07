--- code/client/cl_curl.c.orig	2011-12-24 12:29:31 UTC
+++ code/client/cl_curl.c
@@ -94,6 +94,13 @@ qboolean CL_cURL_Init()
 
 
 	Com_Printf("Loading \"%s\"...", cl_cURLLib->string);
+
+	if ( COM_CompareExtension( cl_cURLLib->string, ".pk3" ) )
+	{
+		Com_Printf( S_COLOR_RED "Rejecting cl_cURLLib named \"%s\"\n", cl_cURLLib->string );
+		return qfalse;
+	}
+
 	if( (cURLLib = Sys_LoadLibrary(cl_cURLLib->string)) == 0 )
 	{
 #ifdef _WIN32
@@ -320,7 +327,7 @@ void CL_cURL_PerformDownload(void)
 	}
 	FS_FCloseFile(clc.download);
 	if(msg->msg == CURLMSG_DONE && msg->data.result == CURLE_OK) {
-		FS_SV_Rename(clc.downloadTempName, clc.downloadName);
+		FS_SV_Rename(clc.downloadTempName, clc.downloadName, qfalse);
 		clc.downloadRestart = qtrue;
 	}
 	else {
