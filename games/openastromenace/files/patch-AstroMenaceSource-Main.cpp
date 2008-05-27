--- AstroMenaceSource/Main.cpp.orig	2007-09-23 00:51:32.000000000 +0400
+++ AstroMenaceSource/Main.cpp	2008-05-19 04:59:05.387115362 +0400
@@ -312,35 +312,7 @@
 	const char* key = "HOME";
 	const char* homeval = getenv(key);
 
-	bool dirpresent = false;
-	for (int i=1; i<argc; i++)
-	{
-		if (!strncmp(argv[i], "--dir=", sizeof("--dir")))
-		{
-			dirpresent = true;
-			// если передали относительный путь в папку пользователя с тильдой
-			if (argv[i][6] != '~')
-				strncpy(ProgrammDir, argv[i]+strlen("--dir="), strlen(argv[i])-strlen("--dir=")+1);
-			else
-			{
-				strcpy(ProgrammDir, homeval);// -1, это тильда... а в кол-ве нет, т.к. /0 там должен остаться
-				strncat(ProgrammDir, argv[i]+strlen("--dir=")+1, strlen(argv[i])-strlen("--dir="));
-			}
-			// если в конце нет слеша - ставим его
-			if (ProgrammDir[strlen(ProgrammDir)-1] != '/')
-				strncat(ProgrammDir, "/", strlen("/"));
-
-		}
-	}
-	if (!dirpresent)
-	{
-		strcpy(ProgrammDir, argv[0]);
-		char* s = strrchr(ProgrammDir,'/');
-		if (s) s[0]=0x0;
-		const char *Fi = "/";
-		strcat( ProgrammDir, Fi );
-	}
-
+	strcpy(ProgrammDir, "/usr/local/share/openastromenace/");
 
 	strcpy(ScreenshotDir, homeval);
 	strcat(ScreenshotDir, "/Desktop/AstroMenaceScreenshot");
