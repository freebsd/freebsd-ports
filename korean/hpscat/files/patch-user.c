--- user.c.orig	1995-11-23 10:17:16 UTC
+++ user.c
@@ -37,7 +37,6 @@ read_rc()
     char buf[BUFSIZ];
     char *home;
     FILE *fp;
-    extern char *getenv PROT((char *));
     home = getenv("HOME");
     if(strlen(home)==0)
         return;
