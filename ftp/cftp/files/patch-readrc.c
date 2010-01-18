--- readrc.c.orig	2010-01-09 23:30:28.000000000 -0800
+++ readrc.c	2010-01-09 23:31:10.000000000 -0800
@@ -46,7 +46,7 @@
     char b[8192], *p, *tok, *q, *home;
     char *user, *pass, *host, *port, *wdir;
 
-    if ((home=getenv("HOME")) == NULL)
+    if ((home=getenv("HOME")) == NULL || strlen(home) > sizeof(b)-9)
 	home = "";
     sprintf(b, "%s/.cftprc", home);
     
