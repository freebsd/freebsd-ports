--- gcc/gcc.c.orig	Sun Sep 22 10:38:27 2002
+++ gcc/gcc.c	Sun Sep 22 10:39:33 2002
@@ -1866,8 +1866,7 @@
 pfatal_with_name (name)
      char *name;
 {
-  extern int errno, sys_nerr;
-  extern char *sys_errlist[];
+  extern int errno;
   char *s;
 
   if (errno < sys_nerr)
@@ -1880,8 +1879,7 @@
 perror_with_name (name)
      char *name;
 {
-  extern int errno, sys_nerr;
-  extern char *sys_errlist[];
+  extern int errno;
   char *s;
 
   if (errno < sys_nerr)
@@ -1894,8 +1892,7 @@
 perror_exec (name)
      char *name;
 {
-  extern int errno, sys_nerr;
-  extern char *sys_errlist[];
+  extern int errno;
   char *s;
 
   if (errno < sys_nerr)
