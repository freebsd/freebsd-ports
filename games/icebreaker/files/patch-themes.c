--- ./themes.c.orig	2002-05-31 05:49:53.000000000 +0200
+++ ./themes.c	2013-12-24 13:42:35.000000000 +0100
@@ -192,7 +192,7 @@
 
 	foundcolor.spritetransparent = 0;
 	
-	snprintf(themefilename, 256,"%s/%s%s",DATAPREFIX,themename,THEMEFILEEXTENSION);
+	snprintf(themefilename, sizeof(themefilename),"%s/%s%s",DATAPREFIX,themename,THEMEFILEEXTENSION);
 	
 	themefile=fopen(themefilename,"r");
 	if (themefile==NULL)
@@ -338,7 +338,7 @@
 						               "We'll try to load it anyway, but don't be surpised if there's a problem.\n"
 						               "(Filename is %s)\n",themename,valbuf);
 					}
-					snprintf(loadfilebuf, 256,"%s/%s",DATAPREFIX,valbuf);
+					snprintf(loadfilebuf, sizeof(loadfilebuf),"%s/%s",DATAPREFIX,valbuf);
 					spriteimage=loadsprite(themename,loadfilebuf);
 				}
 				else if (!strcmp(optbuf,"spritemirrorbitmap"))
@@ -349,7 +349,7 @@
 						               "We'll try to load it anyway, but don't be surpised if there's a problem.\n"
 						               "(Filename is %s)\n",themename,valbuf);
 					}
-					snprintf(loadfilebuf, 256,"%s/%s",DATAPREFIX,valbuf);
+					snprintf(loadfilebuf, sizeof(loadfilebuf),"%s/%s",DATAPREFIX,valbuf);
 					spritemirrorimage=loadsprite(themename,loadfilebuf);
 				}
 				else if (!strcmp(optbuf,"soundouch"))
@@ -360,7 +360,7 @@
 						               "We'll try to load it anyway, but don't be surpised if there's a problem.\n"
 						               "(Filename is %s)\n",themename,valbuf);
 					}
-					snprintf(loadfilebuf, 256,"%s/%s",DATAPREFIX,valbuf);
+					snprintf(loadfilebuf, sizeof(loadfilebuf),"%s/%s",DATAPREFIX,valbuf);
 					loadsounds(themename,loadfilebuf,NULL);
 				}
 				else if (!strcmp(optbuf,"soundcrash"))
@@ -483,11 +483,11 @@
 	{
 		fprintf(stderr,"Hey! You can't have a theme named random! Please remove the random.ibt\n"
 		        "file from your themes directory.\n");
-		snprintf(themename,MAXTHEMENAMELENGTH+1,"linux");
+		strcpy(themename,"linux");
 	}
 	else
 	{
-		snprintf(themename,MAXTHEMENAMELENGTH+1,themelist[random() %themecount]);
+		snprintf(themename,sizeof(themename),"%s",themelist[random() %themecount]);
 	}
 	freethemenames(&themelist,themecount);
 	return settheme(themename);
