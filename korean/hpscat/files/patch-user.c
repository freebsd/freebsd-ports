--- user.c.orig	1995-11-23 05:17:16.000000000 -0500
+++ user.c	2013-06-12 17:24:33.000000000 -0400
@@ -37,7 +37,6 @@
     char buf[BUFSIZ];
     char *home;
     FILE *fp;
-    extern char *getenv PROT((char *));
     home = getenv("HOME");
     if(strlen(home)==0)
         return;
