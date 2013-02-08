--- options.c.orig	2002-05-31 05:15:46.000000000 +0200
+++ options.c	2013-01-13 19:54:42.000000000 +0100
@@ -66,7 +66,7 @@
 	options.autopause=AUTOPAUSEOFF;	
 	options.difficulty=NORMAL;
 	options.fullscreen=FULLSCREENOFF;
-	snprintf(options.theme,MAXTHEMENAMELENGTH+1,"linux");
+	strcpy(options.theme,"linux");
 }
 
 int readoptions(void)
@@ -81,7 +81,7 @@
 
 	setdefaultoptions();
 	
-	snprintf(filename,255,"%s/%s",homedir,OPTIONFILE);
+	snprintf(filename,sizeof(filename),"%s/%s",homedir,OPTIONFILE);
 	
 	optionfile=fopen(filename,"r");
 	if (optionfile==NULL)
@@ -99,7 +99,7 @@
 		}
 		
 		sprintf(scanformat,"%%20s %%%ds",10+MAXTHEMENAMELENGTH);	
-		if (sscanf(linebuf,"%20s %10s",optbuf,valbuf)==2)
+		if (sscanf(linebuf,"%19s %9s",optbuf,valbuf)==2)
 		{
 			if (!strcmp(optbuf,"sound"))
 			{
@@ -135,7 +135,7 @@
 			}
 			else if (!strcmp(optbuf,"theme"))
 			{
-				snprintf(options.theme,MAXTHEMENAMELENGTH+1,"%s",valbuf);
+				snprintf(options.theme,sizeof(options.theme),"%s",valbuf);
 			}
 			// FIX: add username
 		}
@@ -150,7 +150,7 @@
 {
 	FILE * optionfile;
 	char filename[255];
-	snprintf(filename,255,"%s/%s",homedir,OPTIONFILE);
+	snprintf(filename,sizeof(filename),"%s/%s",homedir,OPTIONFILE);
 	
 	optionfile=fopen(filename,"w");
 	if (optionfile==NULL)
@@ -292,7 +292,7 @@
 			else
 			{
 				// fix -- we should probably search for malicious characters here.
-				snprintf(commandline.theme,MAXTHEMENAMELENGTH+1,"%s",argv[i]+strlen(FLAGTHEME));
+				snprintf(commandline.theme,sizeof(commandline.theme),"%s",argv[i]+strlen(FLAGTHEME));
 			}	
 		}
 		else if (strncmp(argv[i],FLAGTHEMELONG "=" ,strlen(FLAGTHEMELONG "=")) == 0)
@@ -312,7 +312,7 @@
 			else
 			{
 				// fix -- we should probably search for malicious characters here.
-				snprintf(commandline.theme,MAXTHEMENAMELENGTH+1,"%s",argv[i]+strlen(FLAGTHEMELONG "="));
+				snprintf(commandline.theme,sizeof(commandline.theme),"%s",argv[i]+strlen(FLAGTHEMELONG "="));
 			}	
 		}
 		else if (strncmp(argv[i],FLAGTHEMELONG,strlen(FLAGTHEMELONG)) == 0)
