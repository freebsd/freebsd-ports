--- columns.cc.orig	2000-03-17 03:52:55.000000000 +0300
+++ columns.cc	2014-12-02 05:13:18.850698698 +0300
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
@@ -269,6 +268,7 @@
     for (int i=0; i<256; i++) {
 	data[i] = NULL;
 	fnt->w[i] = fnt->h[i]= fnt->x[i] = 0;
+	fnt->strut = 0;
     }
   
     // read character chunks one by one
@@ -357,7 +357,7 @@
 
 void highscore_save()
 {
-    char *fname = find_datafile("columns.hsc");
+    char *fname = "/var/games/columns.hsc";
     FILE *fp = fopen(fname,"wb");
     if (fp != NULL) {
 	for (int i=0; i<HIGHSCORE_ENTRIES; i++)
@@ -369,7 +369,7 @@
 void highscore_load()
 {
     char line[30];
-    char *fname = find_datafile("columns.hsc");
+    char *fname = "/var/games/columns.hsc";
     FILE *fp = fopen(fname,"rb");
     if (fp != NULL) {
 	for (int i=0; i<HIGHSCORE_ENTRIES; i++) {
@@ -1365,6 +1365,7 @@
     }
 }
 
+int
 main (int argc, char **argv)
 {
     eval_args(argc, argv);
