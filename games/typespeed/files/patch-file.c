--- file.c.orig	Mon Apr  3 15:44:40 2006
+++ file.c	Mon Apr  3 15:47:21 2006
@@ -492,8 +492,8 @@
 	char tmp[10];
 	char *userhome;
 
-	userhome = malloc(1+strlen(getenv("HOME"))+strlen(LOCALCONF)*sizeof(char));
-	sprintf(userhome,getenv("HOME"));
+	userhome = malloc((2+strlen(getenv("HOME"))+strlen(LOCALCONF))*sizeof(char));
+	strcpy(userhome,getenv("HOME"));
 	strcat(userhome,"/");
 	strcat(userhome,LOCALCONF);
 	hakemisto = malloc(1026 * sizeof(char));
