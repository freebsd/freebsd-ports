--- moon_lander.c.orig	Wed Aug 22 13:52:28 2001
+++ moon_lander.c	Thu Jun 26 22:23:46 2003
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -37,7 +38,7 @@
 #define YSIZE 480
 #define TERRAIN_YSIZE (YSIZE / 2)
 #define FPS (1000 / 35)
-#define DATAPATH ""
+#define DATAPATH "%%PREFIX%%/share/moonlander/"
 
 #define FRESHRUN   0
 #define GAMEOVER   1
@@ -175,9 +176,10 @@
 
   char filename[1024];
   DIR *dir;
-  struct dirent *files[100];
-  int done = 0;
+  char *bg[100];
+  struct dirent *d;
   int count = 0;
+  int i;
   
   /* read images/backgrounds dir and choose a random image from there.
    *  put it's filename in image_file 
@@ -185,27 +187,20 @@
 
 
 
-    sprintf(filename, "%simages/backgrounds",  DATAPATH);
+    snprintf(filename, sizeof filename, "%simages/backgrounds",  DATAPATH);
 
     if ( !(dir = opendir(filename)) ){
       /* error */
       printf("cannot open dir %s\n", filename);
       exit(0);
     }
-  
-    while (!done){
-      if ( files[count] = readdir(dir) ){
-      
-	//printf("I see - %d %s\n", count, files[count]->d_name);
-	count++;
-      }
-      else{
-	done = 1;
-      }
-    
-      if (count > 99) {
-	done = 1;
-      }
+
+    while ( (d = readdir(dir)) != NULL){
+    	if (!strcmp(d->d_name, ".") || !strcmp(d->d_name, ".."))
+	    continue;
+	bg[count++] = strdup(d->d_name);
+	if (count >= 100)
+	    break;
     }
     
     closedir(dir);
@@ -221,12 +216,12 @@
 
   game->back_no++;
   
-  if (game->back_no < 2){
-    game->back_no = 2;
+  if (game->back_no < 0){
+    game->back_no = 0;
   }
 
   if (game->back_no >= count){
-    game->back_no = 2;
+    game->back_no = 0;
   }
   
 
@@ -240,7 +235,9 @@
 
   //printf("about to get new background: %d\n", game->back_no );
 
-  sprintf(filename, "%simages/backgrounds/%s", DATAPATH, files[game->back_no]->d_name);
+  snprintf(filename, sizeof(filename), "%simages/backgrounds/%s", DATAPATH, bg[game->back_no]);
+  for (i = 0; i < count; i++)
+  	free(bg[i]);
   
   // printf("got %s\n", filename);
 
