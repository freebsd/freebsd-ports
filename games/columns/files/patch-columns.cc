--- columns.cc.orig	2000-03-17 00:52:55 UTC
+++ columns.cc
@@ -22,10 +22,9 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <time.h>
-#include <SDL/SDL.h>
+#include <SDL.h>
 
 #define HIGHSCORE_X 10
 #define HIGHSCORE_Y 30
@@ -269,6 +268,7 @@ Font *load_font(const char *fname)
     for (int i=0; i<256; i++) {
 	data[i] = NULL;
 	fnt->w[i] = fnt->h[i]= fnt->x[i] = 0;
+	fnt->strut = 0;
     }
   
     // read character chunks one by one
@@ -357,7 +357,7 @@ highscore_entry highscore[HIGHSCORE_ENTRIES];
 
 void highscore_save()
 {
-    char *fname = find_datafile("columns.hsc");
+    char *fname = "/var/games/columns.hsc";
     FILE *fp = fopen(fname,"wb");
     if (fp != NULL) {
 	for (int i=0; i<HIGHSCORE_ENTRIES; i++)
@@ -369,7 +369,7 @@ void highscore_save()
 void highscore_load()
 {
     char line[30];
-    char *fname = find_datafile("columns.hsc");
+    char *fname = "/var/games/columns.hsc";
     FILE *fp = fopen(fname,"rb");
     if (fp != NULL) {
 	for (int i=0; i<HIGHSCORE_ENTRIES; i++) {
@@ -1360,11 +1360,12 @@ void eval_args(int argc, char **argv)
 	}
     }
     if (show_usage) {
-	printf("Columns "VERSION" - Copyright (C) 1999,2000 Daniel Heck\n");
+	printf("Columns " VERSION " - Copyright (C) 1999,2000 Daniel Heck\n");
 	printf("usage: columns [--nosound] [--bg=filename.bmp]\n\n");
     }
 }
 
+int
 main (int argc, char **argv)
 {
     eval_args(argc, argv);
