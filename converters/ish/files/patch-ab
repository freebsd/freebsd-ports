--- ish.c.orig	Sun Aug  5 20:04:08 1990
+++ ish.c	Fri Mar 29 15:18:25 2002
@@ -48,7 +48,7 @@
 long lsize;
 char *filename = "file.ish";
 
-FILE *opath = stdout;
+FILE *opath = NULL;
 FILE *ipath;
 char name[NAMLEN];
 
@@ -61,7 +61,7 @@
 static int ishargc=0;
 static char *ishargv[32];
 
-void main(argc, argv)
+int main(argc, argv)
 int argc;
 char **argv;
 {
@@ -69,6 +69,7 @@
     char *p;
     FILE *fopen();
 
+    opath = stdout;
     if (argc < 2)
 	help();
     while(--argc > 0) {
