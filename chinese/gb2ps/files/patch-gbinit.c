--- gbinit.c.orig	1992-08-23 11:37:58.000000000 +0800
+++ gbinit.c	2013-09-26 21:00:49.000000000 +0800
@@ -98,11 +98,12 @@ char **arglist;
 	exit (1);
   }
 
-  if (*pathname==0)
+  if (*pathname==0) {
   	if (getenv("CFONT")!=NULL)
  		strcpy(pathname,getenv("CFONT"));
 	else
     		strcpy (pathname,CFONT);
+  }
 
  strcpy(cfont_name,pathname); strcat(cfont_name,SONGTI); 
  if ((cfont = fopen (cfont_name, "r"))!=NULL) {
@@ -185,7 +186,7 @@ char **arglist;
   return k;
 }
 
-
+void
 cleanup(i)
 int i;
 {
@@ -201,5 +202,3 @@ int i;
   if (cfont!=CHFONT[4].fp) fclose(CHFONT[4].fp);
   if (cfont!=CHFONT[5].fp) fclose(CHFONT[5].fp);
 }
-
-
