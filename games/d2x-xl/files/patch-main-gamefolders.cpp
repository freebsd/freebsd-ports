--- main/gamefolders.cpp.orig	2009-09-08 15:00:31.000000000 +0200
+++ main/gamefolders.cpp	2009-09-10 02:55:54.000000000 +0200
@@ -112,7 +112,7 @@
 // ----------------------------------------------------------------------------
 
 #ifdef _WIN32
-#	define	STD_GAMEDIR		""
+#	define	STD_GAMEDIR		"./"
 #	define	D2X_APPNAME		"d2x-xl.exe"
 #elif defined(__macosx__)
 #	define	STD_GAMEDIR		"/Applications/Games/D2X-XL"
@@ -228,8 +228,6 @@
 #	endif //__unix__
 if (!*gameFolders.szGameDir && GetAppFolder ("", gameFolders.szGameDir, STD_GAMEDIR, ""))
 		*gameFolders.szGameDir = '\0';
-if (!*gameFolders.szGameDir && GetAppFolder ("", gameFolders.szGameDir, SHAREPATH, ""))
-		*gameFolders.szGameDir = '\0';
 #	ifdef __macosx__
 GetOSXAppFolder (szDataRootDir, gameFolders.szGameDir);
 #	else
@@ -732,19 +730,16 @@
 if ((i = FindArg ("-userdir")) && pszArgList [i + 1] && *pszArgList [i + 1]) {
 	strcpy (szRootFolder, pszArgList [i + 1]);
 	i = int (strlen (szRootFolder));
-#if defined(__unix__)
-	if (szRootFolder [i - 1] != '/')
-		strcat (szRootFolder, "/");
-#else
-	if ((szRootFolder [i - 1] != '\\') && (szRootFolder [i - 1] != '/') && (szRootFolder [i - 1] != ':'))
-		strcat (szRootFolder, "/");
-#endif
 	}
 else
+	strcpy (szRootFolder, STD_GAMEDIR);
+
 #if defined(__unix__)
-	strcpy (szRootFolder, "/usr/local/games/d2x-xl/");
+if (szRootFolder [i - 1] != '/')
+	strcat (szRootFolder, "/");
 #else
-	strcpy (szRootFolder, "./");
+if ((szRootFolder [i - 1] != '\\') && (szRootFolder [i - 1] != '/') && (szRootFolder [i - 1] != ':'))
+	strcat (szRootFolder, "/");
 #endif
 
 #if defined(__unix__)
