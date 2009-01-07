--- AstroMenaceSource/Main.cpp.orig	2008-12-27 18:25:49.000000000 +0100
+++ AstroMenaceSource/Main.cpp	2008-12-27 18:35:49.000000000 +0100
@@ -312,38 +312,7 @@
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
-#ifdef DATADIR
-		strcpy(ProgrammDir, DATADIR "/");
-#else
- 		strcpy(ProgrammDir, argv[0]);
- 		char* s = strrchr(ProgrammDir,'/');
- 		if (s) s[0]=0x0;
- 		const char *Fi = "/";
- 		strcat( ProgrammDir, Fi );
-#endif
-	}
+        strcpy(ProgrammDir, "/usr/local/share/openastromenace/");
 
 
 	strcpy(ScreenshotDir, homeval);
