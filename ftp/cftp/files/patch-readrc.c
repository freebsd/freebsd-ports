--- readrc.c.orig	2002-09-16 12:42:41 UTC
+++ readrc.c
@@ -46,7 +46,7 @@ readrc(char **userp, char **passp, char 
     char b[8192], *p, *tok, *q, *home;
     char *user, *pass, *host, *port, *wdir;
 
-    if ((home=getenv("HOME")) == NULL)
+    if ((home=getenv("HOME")) == NULL || strlen(home) > sizeof(b)-9)
 	home = "";
     sprintf(b, "%s/.cftprc", home);
     
