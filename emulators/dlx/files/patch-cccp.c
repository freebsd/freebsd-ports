--- gcc/cccp.c.orig	Sun Sep 22 10:45:02 2002
+++ gcc/cccp.c	Sun Sep 22 10:46:22 2002
@@ -4751,8 +4751,7 @@
 {
   int i;
   FILE_BUF *ip = NULL;
-  extern int errno, sys_nerr;
-  extern char *sys_errlist[];
+  extern int errno;
 
   for (i = indepth; i >= 0; i--)
     if (instack[i].fname != NULL) {
@@ -5388,8 +5387,7 @@
 perror_with_name (name)
      char *name;
 {
-  extern int errno, sys_nerr;
-  extern char *sys_errlist[];
+  extern int errno;
 
   fprintf (stderr, "%s: ", progname);
   if (errno < sys_nerr)
