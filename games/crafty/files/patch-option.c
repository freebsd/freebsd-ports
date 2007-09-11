--- option.c.orig	Tue Jun 20 07:57:17 2006
+++ option.c	Mon Sep 10 14:53:11 2007
@@ -1331,9 +1331,11 @@
   else if (OptionMatch("help", *args)) {
     FILE *helpfile;
     char *readstat = (char *) -1;
+    char fname[128];
     int lines = 0;
 
-    helpfile = fopen("crafty.hlp", "r");
+    sprintf(fname, "%s/crafty.hlp", book_path);
+          helpfile = fopen(fname, "r");
     if (!helpfile) {
       printf("ERROR.  Unable to open \"crafty.hlp\" -- help unavailable\n");
       return (1);
