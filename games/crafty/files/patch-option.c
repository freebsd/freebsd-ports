--- option.c.orig	2016-10-28 05:11:42.000000000 +0200
+++ option.c	2017-07-15 23:35:58.863941000 +0200
@@ -978,9 +978,11 @@ int Option(TREE * RESTRICT tree) {
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
       return 1;
