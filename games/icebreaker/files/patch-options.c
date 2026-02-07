--- ./options.c.orig	2002-06-16 22:35:13.000000000 +0200
+++ ./options.c	2013-12-24 13:42:35.000000000 +0100
@@ -87,7 +87,7 @@
 	options.autopause=AUTOPAUSEOFF;	
 	options.difficulty=NORMAL;
 	options.fullscreen=FULLSCREENOFF;
-	snprintf(options.theme,MAXTHEMENAMELENGTH+1,"linux");
+	strcpy(options.theme,"linux");
 }
 
 int readoptions(void)
@@ -102,7 +102,7 @@
 
 	setdefaultoptions();
 	
-	snprintf(filename,255,"%s/%s",homedir,OPTIONFILE);
+	snprintf(filename,sizeof(filename),"%s/%s",homedir,OPTIONFILE);
 	
 	optionfile=openoptionfile(filename,"r");
 	if (optionfile==NULL)
@@ -120,7 +120,7 @@
 		}
 		
 		sprintf(scanformat,"%%20s %%%ds",10+MAXTHEMENAMELENGTH);	
-		if (sscanf(linebuf,"%20s %10s",optbuf,valbuf)==2)
+		if (sscanf(linebuf,"%19s %9s",optbuf,valbuf)==2)
 		{
 			if (!strcmp(optbuf,"sound"))
 			{
@@ -156,7 +156,7 @@
 			}
 			else if (!strcmp(optbuf,"theme"))
 			{
-				snprintf(options.theme,MAXTHEMENAMELENGTH+1,"%s",valbuf);
+				snprintf(options.theme,sizeof(options.theme),"%s",valbuf);
 			}
 			// FIX: add username
 		}
@@ -171,7 +171,7 @@
 {
 	OPTFILEHANDLER * optionfile;
 	char filename[255];
-	snprintf(filename,255,"%s/%s",homedir,OPTIONFILE);
+	snprintf(filename,sizeof(filename),"%s/%s",homedir,OPTIONFILE);
 	
 	optionfile=openoptionfile(filename,"w");
 	if (optionfile==NULL)
@@ -313,7 +313,7 @@
 			else
 			{
 				// fix -- we should probably search for malicious characters here.
-				snprintf(commandline.theme,MAXTHEMENAMELENGTH+1,"%s",argv[i]+strlen(FLAGTHEME));
+				snprintf(commandline.theme,sizeof(commandline.theme),"%s",argv[i]+strlen(FLAGTHEME));
 			}	
 		}
 		else if (strncmp(argv[i],FLAGTHEMELONG "=" ,strlen(FLAGTHEMELONG "=")) == 0)
@@ -333,7 +333,7 @@
 			else
 			{
 				// fix -- we should probably search for malicious characters here.
-				snprintf(commandline.theme,MAXTHEMENAMELENGTH+1,"%s",argv[i]+strlen(FLAGTHEMELONG "="));
+				snprintf(commandline.theme,sizeof(commandline.theme),"%s",argv[i]+strlen(FLAGTHEMELONG "="));
 			}	
 		}
 		else if (strncmp(argv[i],FLAGTHEMELONG,strlen(FLAGTHEMELONG)) == 0)
